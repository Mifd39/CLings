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

    // Check if unshare is available
    if is_command_available("unshare") {
        let mut cmd = Command::new("unshare");
        cmd.args(&["-n", "-r", program]);
        return (cmd, vec!["Warning: 'bwrap' not found. Filesystem is not protected. Only network is isolated.".to_string()]);
    }

    // Fallback
    let cmd = Command::new(program);
    (cmd, vec!["Warning: Neither 'bwrap' nor 'unshare' found. Running without sandbox protection.".to_string()])
}

#[cfg(target_os = "macos")]
pub fn command(program: &str) -> (Command, Vec<String>) {
    let mut cmd = Command::new("sandbox-exec");
    let profile = "(version 1) (allow default) (deny network*) (deny file-write*) (allow file-write* \"/dev/tty\")";
    cmd.args(&["-p", profile, program]);
    (cmd, vec![])
}

#[cfg(target_os = "windows")]
pub fn command(program: &str) -> (Command, Vec<String>) {
    // On Windows, we rely on WSL for security.
    let cmd = Command::new(program);
    (cmd, vec![])
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
