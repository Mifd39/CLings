# CLings

CLings is a small tool to help you get used to reading and writing C code. It mimics the popular "Rustlings" and "Ziglings" projects.

## Prerequisites

- **Rust**: You need to have the Rust toolchain installed to run the `clings` tool. [Install Rust](https://www.rust-lang.org/tools/install).
- **GCC**: You need a C compiler (`gcc`) installed and available in your path.

## Getting Started

1.  **Install Dependencies:**
    Ensure you have `gcc` installed.
    - Linux: `sudo apt install build-essential`
    - macOS: `xcode-select --install`
    - Windows: Install MinGW or use WSL.

2.  **Run the Tool:**
    From the repository root, run:
    ```bash
    cargo run -- watch
    ```

3.  **Solve Exercises:**
    - The tool will tell you which exercise to solve (starting with `intro1`).
    - Open the file in your favorite editor (e.g., `exercises/1_intro/intro1.c`).
    - Follow the instructions in the comments.
    - Remove the line `// I AM NOT DONE` when you think you are finished.
    - Save the file.
    - The tool will automatically re-compile and verify your solution.

4.  **Challenges:**
    - After every few topics, there is a challenge exercise.
    - These require you to combine multiple concepts learned so far.
    - They are slightly harder than regular exercises and may require some problem solving!

## Commands

- `watch`: Automatically re-runs verification when files change.
- `verify`: Runs the verification once for all exercises until the first failure.
- `list`: Lists all available exercises.

## License

MIT
