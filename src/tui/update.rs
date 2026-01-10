use crossterm::event::{KeyCode, KeyEvent};
use std::sync::mpsc;
use std::path::PathBuf;
use notify::{Watcher, RecursiveMode};

use crate::tui::model::{App, SelectionMode};
use crate::verify::verify_exercise;

pub enum AppEvent {
    FileChanged(PathBuf),
}

pub enum Action {
    Continue,
    Quit,
    OpenEditor(PathBuf),
}

pub fn handle_key_event(app: &mut App, key: KeyEvent) -> Action {
    if app.show_hint {
        if let KeyCode::Esc | KeyCode::Char('h') = key.code {
            app.show_hint = false;
        }
        return Action::Continue;
    }

    match key.code {
        KeyCode::Char('q') => return Action::Quit,
        KeyCode::Char('h') => app.show_hint = true,
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

pub fn handle_watcher_events(app: &mut App, rx: &mpsc::Receiver<AppEvent>) {
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
                    // Trigger verification
                    let res = verify_exercise(&ex_clone);
                    if let Ok(output) = res {
                        if output.success {
                            app.progress.mark_completed(ex_name);
                        }
                        app.output = Some(output);
                    } else if let Err(e) = res {
                         app.output = Some(crate::verify::VerificationOutput {
                             success: false,
                             stdout: String::new(),
                             stderr: format!("Error running verification: {}", e),
                         });
                    }
                    app.processing = false;
                }
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
