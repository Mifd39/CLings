use crate::exercise::{Exercise, Mode};
use colored::Colorize;
use std::fs;
use std::io::Write;
use std::process::{Command, Stdio};

#[derive(Debug, Clone)]
pub struct VerificationOutput {
    pub success: bool,
    pub stdout: String,
    pub stderr: String,
}

pub fn verify_all(exercises: &[Exercise]) {
    for exercise in exercises {
        match verify_exercise(exercise) {
            Ok(output) => {
                if output.success {
                    println!("{} {}", "✓".green(), exercise.name.green());
                } else {
                    println!("{} {}", "✗".red(), exercise.name.red());
                    if !output.stdout.is_empty() {
                         println!("Output:\n{}", output.stdout);
                    }
                    if !output.stderr.is_empty() {
                        println!("{}", output.stderr);
                    }
                    println!("\n{}", "Progress halted! Fix this exercise to continue.".yellow());
                    break;
                }
            }
            Err(e) => {
                println!("{} {} - Error: {}", "✗".red(), exercise.name.red(), e);
                break;
            }
        }
    }
}

pub fn verify_exercise(exercise: &Exercise) -> Result<VerificationOutput, String> {
    let source_code = fs::read_to_string(&exercise.path)
        .map_err(|e| format!("Failed to read {:?}: {}", exercise.path, e))?;

    // Check for "I AM NOT DONE"
    if source_code.contains("// I AM NOT DONE") {
        return Ok(VerificationOutput {
            success: false,
            stdout: String::new(),
            stderr: format!("{} is not done yet. Remove '// I AM NOT DONE' to verify.", exercise.name),
        });
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
        return Ok(VerificationOutput {
            success: false,
            stdout: String::new(),
            stderr: format!("{}\n{}", String::from_utf8_lossy(&compile_output.stderr), "Compilation Failed".red()),
        });
    }

    if exercise.mode == Mode::Compile {
        return Ok(VerificationOutput {
            success: true,
            stdout: String::new(),
            stderr: String::new(),
        });
    }

    // Run (for Mode::Run and Mode::Test)
    let (mut cmd, warnings) = crate::sandbox::command(&output_path);

    if exercise.stdin.is_some() {
        cmd.stdin(Stdio::piped());
    }

    let mut child = cmd
        .spawn()
        .map_err(|e| format!("Failed to spawn binary: {}", e))?;

    if let Some(input) = &exercise.stdin {
        if let Some(mut stdin) = child.stdin.take() {
            stdin.write_all(input.as_bytes())
                .map_err(|e| format!("Failed to write to stdin: {}", e))?;
        }
    }

    let run_output = child
        .wait_with_output()
        .map_err(|e| format!("Failed to wait on binary: {}", e))?;

    // Cleanup
    let _ = fs::remove_file(&output_path);
    // Also try to remove .exe for Windows
    let _ = fs::remove_file(format!("{}.exe", output_path));

    if !run_output.status.success() {
         return Ok(VerificationOutput {
            success: false,
            stdout: String::from_utf8_lossy(&run_output.stdout).to_string(),
            stderr: format!("{}\n{}", String::from_utf8_lossy(&run_output.stderr), "Execution Failed (non-zero exit code)".red()),
         });
    }

    let stdout = String::from_utf8_lossy(&run_output.stdout).to_string();
    let mut stderr = String::from_utf8_lossy(&run_output.stderr).to_string();

    // Append sandbox warnings to stderr if any
    if !warnings.is_empty() {
        if !stderr.is_empty() {
            stderr.push('\n');
        }
        for warning in warnings {
            stderr.push_str(&format!("{}\n", warning.yellow()));
        }
    }

    // Verify Output if expected
    if let Some(expected_output) = &exercise.output {
        let expected_trimmed = expected_output.trim();
        let actual_trimmed = stdout.trim();

        if expected_trimmed != actual_trimmed {
            return Ok(VerificationOutput {
                success: false,
                stdout: stdout.clone(),
                stderr: format!(
                    "Output Mismatch!\nExpected:\n{}\n\nActual:\n{}",
                    expected_trimmed.green(),
                    actual_trimmed.red()
                ),
            });
        }
    }

    Ok(VerificationOutput {
        success: true,
        stdout,
        stderr,
    })
}
