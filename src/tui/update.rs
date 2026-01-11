use crossterm::event::{KeyCode, KeyEvent};
use std::sync::mpsc;
use std::path::PathBuf;
use notify::{Watcher, RecursiveMode};
use std::thread;

use crate::tui::model::{App, SelectionMode};
use crate::verify::{verify_exercise, VerificationOutput};

pub enum AppEvent {
    FileChanged(PathBuf),
    VerificationDone(String, VerificationOutput),
}

pub enum Action {
    Continue,
    Quit,
    OpenEditor(PathBuf),
}

pub fn handle_key_event(app: &mut App, key: KeyEvent) -> Action {
    if app.show_quit_popup {
        match key.code {
            KeyCode::Char('y') | KeyCode::Enter => return Action::Quit,
            KeyCode::Char('n') | KeyCode::Esc | KeyCode::Char('q') => {
                app.show_quit_popup = false;
            }
            _ => {}
        }
        return Action::Continue;
    }

    if app.show_hint {
        if let KeyCode::Esc | KeyCode::Char('h') = key.code {
            app.show_hint = false;
        }
        return Action::Continue;
    }

    match key.code {
        KeyCode::Char('q') => {
            app.show_quit_popup = true;
        }
        KeyCode::Char('h') => {
            if app.selection_mode == SelectionMode::Exercise {
                app.show_hint = true;
            }
        }
        KeyCode::Char('l') => {
            if app.selection_mode == SelectionMode::Topic {
                app.toggle_topic();
            }
        }
        KeyCode::Down | KeyCode::Char('j') => app.next(),
        KeyCode::Up | KeyCode::Char('k') => app.previous(),
        KeyCode::Enter | KeyCode::Char('e') => {
            match app.selection_mode {
                SelectionMode::Topic => {
                    app.toggle_topic();
                }
                SelectionMode::Exercise => {
                    if let Some(ex) = app.current_exercise() {
                        return Action::OpenEditor(ex.path.clone());
                    }
                }
            }
        }
        _ => {}
    }
    Action::Continue
}

pub fn handle_watcher_events(app: &mut App, rx: &mpsc::Receiver<AppEvent>, tx: mpsc::Sender<AppEvent>) {
    // Process all pending events
    while let Ok(event) = rx.try_recv() {
        match event {
            AppEvent::FileChanged(path) => {
                // Check if the changed file matches the current exercise
                let (ex_path, ex_name, ex_clone) = if let Some(current_exercise) = app.current_exercise() {
                    (current_exercise.path.clone(), current_exercise.name.clone(), current_exercise.clone())
                } else {
                    continue;
                };

                // We check if the changed path ends with the current exercise path
                if path.ends_with(&ex_path) {
                    app.processing = true;
                    // Trigger verification in a separate thread
                    let tx_clone = tx.clone();
                    thread::spawn(move || {
                        let res = verify_exercise(&ex_clone);
                        match res {
                            Ok(output) => {
                                let _ = tx_clone.send(AppEvent::VerificationDone(ex_name, output));
                            }
                            Err(e) => {
                                let output = VerificationOutput {
                                    success: false,
                                    stdout: String::new(),
                                    stderr: format!("Error running verification: {}", e),
                                };
                                let _ = tx_clone.send(AppEvent::VerificationDone(ex_name, output));
                            }
                        }
                    });
                }
            }
            AppEvent::VerificationDone(ex_name, output) => {
                app.processing = false;
                // Only update if we are still looking at the same exercise?
                // For now, assume yes, or just update the UI.

                // If it was successful, update progress
                if output.success {
                     app.progress.mark_completed(ex_name);
                }
                app.output = Some(output);
            }
        }
    }
}

pub fn setup_watcher(tx: mpsc::Sender<AppEvent>) -> notify::Result<impl Watcher> {
    let mut watcher = notify::recommended_watcher(move |res: notify::Result<notify::Event>| {
        match res {
            Ok(event) => {
                for path in event.paths {
                     let _ = tx.send(AppEvent::FileChanged(path));
                }
            }
            Err(e) => println!("watch error: {:?}", e),
        }
    })?;

    watcher.watch(std::path::Path::new("exercises"), RecursiveMode::Recursive)?;
    Ok(watcher)
}
