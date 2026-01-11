use std::process::Command;

#[cfg(target_os = "linux")]
pub fn command(program: &str) -> (Command, Vec<String>) {
    // Check if bwrap is available
    if is_command_available("bwrap") {
        let mut cmd = Command::new("bwrap");
        cmd.args(&[
            "--ro-bind", "/", "/",
            "--dev", "/dev",
            "--proc", "/proc",
            "--tmpfs", "/tmp",
            "--unshare-net",
            "--die-with-parent",
            program
        ]);
        return (cmd, vec![]);
    }

    // Insecure Fallback removed. We must fail or warn aggressively if bwrap is missing.
    // To prevent users from unknowingly running unsafe code, we will issue a warning
    // and rely on verify.rs to fail or proceed based on user acceptance?
    // Actually, verify.rs just runs the command.
    // We will return the raw command but with a HUGE warning in the output.
    // Ideally, we should maybe make it error out if configured to do so, but for now:
    // We stick to the request: "Modify Linux sandbox to fail if bwrap is missing"

    // We will cheat slightly: We return a command that PRINTS an error and fails,
    // instead of running the program.
    let mut cmd = Command::new("echo");
    cmd.arg("Error: 'bwrap' not found. Execution blocked for security. Please install 'bubblewrap'.");
    // We also need to ensure it fails with non-zero exit code.
    // 'echo' returns 0. So let's use 'false' or a shell wrapper.
    let mut cmd = Command::new("sh");
    cmd.args(&["-c", "echo \"Error: 'bwrap' not found. Execution blocked for security. Please install 'bubblewrap'.\"; exit 1"]);

    (cmd, vec!["Error: 'bwrap' is required for secure execution on Linux.".to_string()])
}

#[cfg(target_os = "macos")]
pub fn command(program: &str) -> (Command, Vec<String>) {
    let mut cmd = Command::new("sandbox-exec");
    let profile = "(version 1) (allow default) (deny network*) (deny file-write*) (allow file-write* \"/dev/tty\") (allow file-write* \"/tmp/*\") (allow file-write* \"/private/tmp/*\")";
    cmd.args(&["-p", profile, program]);
    (cmd, vec![])
}

#[cfg(target_os = "windows")]
pub fn command(program: &str) -> (Command, Vec<String>) {
    // On Windows, we rely on WSL for security.
    let cmd = Command::new(program);
    (cmd, vec!["Warning: Windows execution is NOT sandboxed. Use WSL for better security.".to_string()])
}

// Fallback for other OSes (e.g. BSD)
#[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows")))]
pub fn command(program: &str) -> (Command, Vec<String>) {
    let cmd = Command::new(program);
    (cmd, vec!["Warning: Sandboxing not supported on this OS.".to_string()])
}

#[cfg(target_os = "linux")]
fn is_command_available(program: &str) -> bool {
    Command::new("which")
        .arg(program)
        .output()
        .map(|output| output.status.success())
        .unwrap_or(false)
}
