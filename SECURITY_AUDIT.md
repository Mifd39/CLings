# Security Audit Report for `clings`

## Executive Summary
A security audit was performed on the `clings` codebase. The audit focused on the execution sandbox, input validation, and resource management.
**Critical** vulnerabilities were found regarding Denial of Service (DoS) and potential Arbitrary File Write issues due to lack of input validation.
**High** severity issues exist regarding the fallback mechanisms for sandboxing on Linux and the complete lack of sandboxing on Windows.

## Findings

### 1. Denial of Service (DoS) via Infinite Loops
*   **Severity:** **Critical**
*   **Location:** `src/verify.rs`, `src/tui/update.rs`
*   **Description:** The verification process runs synchronously within the main TUI thread. The `Command::wait_with_output()` method in `src/verify.rs` waits indefinitely for the child process to exit.
*   **Impact:** If a user writes an infinite loop (e.g., `while(1);`), the compiler or the compiled binary will never exit. This freezes the entire `clings` application, requiring the user to manually kill the process from another terminal.
*   **Recommendation:**
    *   Implement a timeout for both compilation and execution commands.
    *   Run verification in a separate thread (or async task) so the TUI remains responsive and can allow the user to cancel the operation.

### 2. Path Traversal & Arbitrary File Write
*   **Severity:** **High**
*   **Location:** `src/verify.rs`, `src/exercise.rs`
*   **Description:** The `Exercise` struct is deserialized directly from `info.toml` without validation. The `verify_exercise` function uses `exercise.name` to construct the temporary output path: `format!("target/temp_{}", exercise.name)`.
*   **Impact:** A malicious `info.toml` could set `name` to `../../../../bin/malicious`. This would cause `gcc` to write the compiled binary to a location outside the `target` directory, potentially overwriting system files or user data (permission permitting).
*   **Recommendation:**
    *   Validate `exercise.name` to ensure it contains only alphanumeric characters and underscores.
    *   Validate `exercise.path` to ensure it stays within the `exercises/` directory.

### 3. Insecure Sandbox Fallback (Linux)
*   **Severity:** **High**
*   **Location:** `src/sandbox.rs`
*   **Description:** If `bwrap` is not found, the system falls back to `unshare -n -r`. This command only isolates the network namespace. It **does not** isolate the filesystem.
*   **Impact:** A user running `clings` on Linux without `bwrap` installed is vulnerable to filesystem damage (e.g., `rm -rf ~`) from a malicious or accidental C program.
*   **Recommendation:**
    *   If `bwrap` is missing, fail securely by default or strictly warn the user and require an explicit "unsafely-run" flag.
    *   Do not silently fall back to a non-filesystem sandbox.

### 4. Lack of Sandboxing on Windows
*   **Severity:** **Medium**
*   **Location:** `src/sandbox.rs`
*   **Description:** The Windows implementation returns a raw command without any sandboxing.
*   **Impact:** Windows users have zero protection against malicious code.
*   **Recommendation:**
    *   Detect if running inside WSL and warn if not.
    *   Explore Windows-specific sandboxing (e.g., AppContainers) or clearly mark Windows support as "Insecure/Experimental".

### 5. Race Conditions in Temporary Files
*   **Severity:** **Low**
*   **Location:** `src/verify.rs`
*   **Description:** Temporary files are named `target/temp_{exercise.name}`.
*   **Impact:** If two instances of `clings` run simultaneously, or if two exercises have the same name in `info.toml`, they will conflict and overwrite each other's binaries.
*   **Recommendation:** Use a random suffix for temporary files (e.g., `temp_{name}_{uuid}`) or use a dedicated temporary file library.

### 6. Missing Compiler Hardening
*   **Severity:** **Low**
*   **Location:** `src/verify.rs`
*   **Description:** `gcc` is invoked without security flags.
*   **Impact:** Stack buffer overflows in student code will likely crash the process. While this is educational, enabling flags like `-fstack-protector` could provide better error messages and prevent the runner from potentially being exploited (though the runner is separate).
*   **Recommendation:** Add standard hardening flags: `-fstack-protector-strong -D_FORTIFY_SOURCE=2`.
