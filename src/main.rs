pub mod exercise;
pub mod verify;

use clap::{Parser, Subcommand};
use notify::{Config, RecommendedWatcher, RecursiveMode, Watcher};
use std::sync::mpsc::channel;
use std::time::Duration;
use crate::exercise::{Info, Exercise};
use std::fs;
use std::path::Path;

#[derive(Parser)]
#[command(name = "clings")]
#[command(about = "A C language learning tool", long_about = None)]
struct Cli {
    #[command(subcommand)]
    command: Commands,
}

#[derive(Subcommand)]
enum Commands {
    /// List all exercises
    List,
    /// Verify the current exercise (or all)
    Verify,
    /// Watch for changes and re-verify
    Watch,
}

fn main() {
    let cli = Cli::parse();

    match cli.command {
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
             watch_mode();
        }
    }
}

fn watch_mode() {
    println!("Watching for changes in exercises/...");
    let (tx, rx) = channel();
    let mut watcher = RecommendedWatcher::new(tx, Config::default()).unwrap();
    watcher.watch(Path::new("exercises"), RecursiveMode::Recursive).unwrap();

    // Initial run
    {
         let info_content = fs::read_to_string("info.toml").expect("Failed to read info.toml");
         let info: Info = toml::from_str(&info_content).expect("Failed to parse info.toml");
         verify::verify_all(&info.exercises);
    }

    for res in rx {
        match res {
            Ok(_event) => {
                 // Debounce
                 std::thread::sleep(Duration::from_millis(100));

                 // We clear the screen for better UX
                 print!("\x1B[2J\x1B[1;1H");
                 let info_content = fs::read_to_string("info.toml").expect("Failed to read info.toml");
                 let info: Info = toml::from_str(&info_content).expect("Failed to parse info.toml");
                 verify::verify_all(&info.exercises);
            },
            Err(e) => println!("watch error: {:?}", e),
        }
    }
}
