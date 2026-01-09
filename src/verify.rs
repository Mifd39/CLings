use crate::exercise::{Exercise, Mode};
use colored::Colorize;
use std::fs;
use std::process::Command;

pub fn verify_all(exercises: &[Exercise]) {
    for exercise in exercises {
        match verify_exercise(exercise) {
            Ok(true) => {
                println!("{} {}", "✓".green(), exercise.name.green());
            }
            Ok(false) => {
                println!("{} {}", "✗".red(), exercise.name.red());
                println!("\n{}", "Progress halted! Fix this exercise to continue.".yellow());
                break; // Stop at first failure
            }
            Err(e) => {
                println!("{} {} - Error: {}", "✗".red(), exercise.name.red(), e);
                break;
            }
        }
    }
}

fn verify_exercise(exercise: &Exercise) -> Result<bool, String> {
    let source_code = fs::read_to_string(&exercise.path)
        .map_err(|e| format!("Failed to read {:?}: {}", exercise.path, e))?;

    // Check for "I AM NOT DONE"
    if source_code.contains("// I AM NOT DONE") {
        println!("{} is not done yet. Remove '// I AM NOT DONE' to verify.", exercise.name);
        return Ok(false);
    }

    // Compile
    let output_path = format!("target/temp_{}", exercise.name);
    // Ensure target dir exists
    let _ = fs::create_dir_all("target");

    let compile_output = Command::new("gcc")
        .arg(&exercise.path)
        .arg("-o")
        .arg(&output_path)
        .output()
        .map_err(|e| format!("Failed to run gcc: {}", e))?;

    if !compile_output.status.success() {
        println!("{}", String::from_utf8_lossy(&compile_output.stderr));
        println!("{}", "Compilation Failed".red());
        return Ok(false);
    }

    if exercise.mode == Mode::Compile {
        return Ok(true);
    }

    // Run (for Mode::Run and Mode::Test)
    let run_output = Command::new(&output_path)
        .output()
        .map_err(|e| format!("Failed to run binary: {}", e))?;

    if !run_output.status.success() {
         println!("Output:\n{}", String::from_utf8_lossy(&run_output.stdout));
         println!("Errors:\n{}", String::from_utf8_lossy(&run_output.stderr));
         println!("{}", "Execution Failed (non-zero exit code)".red());
         return Ok(false);
    }

    // For now, Mode::Run just checks for exit code 0.
    // Future: Mode::Test could check stdout against expected output.

    // Cleanup
    let _ = fs::remove_file(&output_path);
    // Also try to remove .exe for Windows
    let _ = fs::remove_file(format!("{}.exe", output_path));

    Ok(true)
}
