use crate::exercise::{Exercise, Mode};
use colored::Colorize;
use std::fs;
use std::io::{Write, Read};
use std::process::{Command, Stdio};
use std::time::{Duration, SystemTime, UNIX_EPOCH};
use wait_timeout::ChildExt;

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
    // Input Validation
    if exercise.name.contains("..") || exercise.name.contains('/') || exercise.name.contains('\\') {
        return Err("Invalid exercise name (path traversal detected)".to_string());
    }

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
    let timestamp = SystemTime::now().duration_since(UNIX_EPOCH).unwrap().as_millis();
    let output_path = format!("target/temp_{}_{}", exercise.name, timestamp);
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
        let _ = fs::remove_file(&output_path);
        let _ = fs::remove_file(format!("{}.exe", output_path));
        return Ok(VerificationOutput {
            success: true,
            stdout: String::new(),
            stderr: String::new(),
        });
    }

    // Run (for Mode::Run and Mode::Test)
    let (mut cmd, warnings) = crate::sandbox::command(&output_path);

    // Pass args if present
    if let Some(args) = &exercise.args {
        cmd.args(args);
    }

    cmd.stdout(Stdio::piped())
       .stderr(Stdio::piped());

    if exercise.stdin.is_some() {
        cmd.stdin(Stdio::piped());
    }

    let mut child = cmd
        .spawn()
        .map_err(|e| format!("Failed to spawn binary: {}", e))?;

    if let Some(input) = &exercise.stdin {
        if let Some(mut stdin) = child.stdin.take() {
            let _ = stdin.write_all(input.as_bytes());
            // drop stdin to close it
        }
    }

    // Capture stdout/stderr in separate threads to avoid deadlocks on pipe buffers
    let mut stdout_pipe = child.stdout.take().unwrap();
    let mut stderr_pipe = child.stderr.take().unwrap();

    let stdout_handle = std::thread::spawn(move || {
        let mut buf = Vec::new();
        let _ = stdout_pipe.read_to_end(&mut buf);
        buf
    });

    let stderr_handle = std::thread::spawn(move || {
        let mut buf = Vec::new();
        let _ = stderr_pipe.read_to_end(&mut buf);
        buf
    });

    // 5 second timeout
    let timeout = Duration::from_secs(5);
    let status_res = child.wait_timeout(timeout).map_err(|e| format!("Failed to wait on child: {}", e))?;

    let (status, timed_out) = match status_res {
        Some(status) => (status, false),
        None => {
            // Timed out
            let _ = child.kill();
            // We wait on the killed child to reap the zombie and get its exit status
            let status = child.wait().map_err(|e| format!("Failed to wait on killed child: {}", e))?;
            (status, true)
        }
    };

    let stdout_bytes = stdout_handle.join().unwrap_or_default();
    let stderr_bytes = stderr_handle.join().unwrap_or_default();

    // Cleanup
    let _ = fs::remove_file(&output_path);
    let _ = fs::remove_file(format!("{}.exe", output_path));

    if timed_out {
        return Ok(VerificationOutput {
            success: false,
            stdout: String::from_utf8_lossy(&stdout_bytes).to_string(),
            stderr: format!("{}\n{}", String::from_utf8_lossy(&stderr_bytes), "Execution Timed Out (Possible Infinite Loop)".red()),
        });
    }

    if !status.success() {
         return Ok(VerificationOutput {
            success: false,
            stdout: String::from_utf8_lossy(&stdout_bytes).to_string(),
            stderr: format!("{}\n{}", String::from_utf8_lossy(&stderr_bytes), "Execution Failed (non-zero exit code)".red()),
         });
    }

    let stdout = String::from_utf8_lossy(&stdout_bytes).to_string();
    let mut stderr = String::from_utf8_lossy(&stderr_bytes).to_string();

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
