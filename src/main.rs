pub mod exercise;
pub mod verify;
pub mod sandbox;
pub mod progress;
pub mod tui;

use clap::{Parser, Subcommand};
use crate::exercise::{Info};
use std::fs;
use std::io;
use std::time::Duration;
use std::sync::mpsc;
use std::process::Command;
use std::env;
use crossterm::{
    event::{DisableMouseCapture, EnableMouseCapture, Event},
    execute,
    terminal::{disable_raw_mode, enable_raw_mode, EnterAlternateScreen, LeaveAlternateScreen},
};
use ratatui::{
    backend::{CrosstermBackend, Backend},
    Terminal,
};
use crate::tui::update::Action;

#[derive(Parser)]
#[command(name = "clings")]
#[command(about = "A C language learning tool", long_about = None)]
struct Cli {
    #[command(subcommand)]
    command: Option<Commands>,
}

#[derive(Subcommand)]
enum Commands {
    /// Start the interactive TUI (default)
    Tui,
    /// List all exercises
    List,
    /// Verify the current exercise (or all)
    Verify,
    /// Watch for changes and re-verify
    Watch,
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let cli = Cli::parse();

    match cli.command.unwrap_or(Commands::Tui) {
        Commands::Tui => {
            run_tui()?;
        }
        Commands::List => {
            let info_content = fs::read_to_string("info.toml").expect("Failed to read info.toml");
            let info: Info = toml::from_str(&info_content).expect("Failed to parse info.toml");
            for exercise in info.exercises {
                println!("- {} ({:?})", exercise.name, exercise.mode);
            }
        }
        Commands::Verify => {
            let info_content = fs::read_to_string("info.toml").expect("Failed to read info.toml");
            let info: Info = toml::from_str(&info_content).expect("Failed to parse info.toml");
            verify::verify_all(&info.exercises);
        }
        Commands::Watch => {
             println!("'clings watch' is deprecated. Please use 'clings' to start the interactive TUI.");
             // Run verify once just in case they wanted a check.
             let info_content = fs::read_to_string("info.toml").expect("Failed to read info.toml");
             let info: Info = toml::from_str(&info_content).expect("Failed to parse info.toml");
             verify::verify_all(&info.exercises);
        }
    }
    Ok(())
}

fn run_tui() -> Result<(), Box<dyn std::error::Error>> {
    // Setup terminal
    enable_raw_mode()?;
    let mut stdout = io::stdout();
    execute!(stdout, EnterAlternateScreen, EnableMouseCapture)?;
    let backend = CrosstermBackend::new(stdout);
    let mut terminal = Terminal::new(backend)?;

    // Load exercises
    let info_content = fs::read_to_string("info.toml").expect("Failed to read info.toml");
    let info: Info = toml::from_str(&info_content).expect("Failed to parse info.toml");

    // Create App
    let mut app = tui::model::App::new(info.exercises);

    // Trigger verification for the initial exercise immediately
    if let Some(ex) = app.current_exercise() {
        if let Ok(output) = verify::verify_exercise(ex) {
             app.output = Some(output);
        }
    }

    // Setup watcher
    let (tx, rx) = mpsc::channel();
    let _watcher = tui::update::setup_watcher(tx.clone())?;

    // Run loop
    let res = run_app(&mut terminal, &mut app, rx);

    // Restore terminal
    disable_raw_mode()?;
    execute!(
        terminal.backend_mut(),
        LeaveAlternateScreen,
        DisableMouseCapture
    )?;
    terminal.show_cursor()?;

    if let Err(err) = res {
        println!("{:?}", err)
    }

    Ok(())
}

fn run_app<B: Backend + io::Write>(
    terminal: &mut Terminal<B>,
    app: &mut tui::model::App,
    rx: mpsc::Receiver<tui::update::AppEvent>,
) -> io::Result<()> {
    loop {
        terminal.draw(|f| tui::view::ui(f, app))?;

        if crossterm::event::poll(Duration::from_millis(250))? {
            match crossterm::event::read()? {
                Event::Key(key) => {
                    match tui::update::handle_key_event(app, key) {
                        Action::Quit => return Ok(()),
                        Action::OpenEditor(path) => {
                            // Suspend TUI
                            disable_raw_mode()?;
                            execute!(terminal.backend_mut(), LeaveAlternateScreen, DisableMouseCapture)?;
                            terminal.show_cursor()?;

                            // Run Editor
                            let editor = env::var("EDITOR").unwrap_or_else(|_| "nano".to_string());
                            let _ = Command::new(editor)
                                .arg(path)
                                .status();

                            // Restore TUI
                            execute!(terminal.backend_mut(), EnterAlternateScreen, EnableMouseCapture)?;
                            enable_raw_mode()?;
                            terminal.hide_cursor()?;
                            terminal.clear()?;
                        }
                        Action::Continue => {}
                    }
                },
                Event::Mouse(_mouse) => {
                     // Mouse support future
                }
                _ => {}
            }
        }

        // Handle watcher events
        tui::update::handle_watcher_events(app, &rx);
    }
}
