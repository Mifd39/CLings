# Agent Instructions for `clings`

This file documents the standards for the `clings` course material. For every file you touch, you must obey these instructions.

## Code Quality Standards

1.  **Formatting**:
    -   No tab characters. Use 4 spaces for indentation.
    -   No trailing whitespace on any line.
    -   Every file must end with exactly one newline character.

2.  **Exercise Structure**:
    -   **Header**: Every file must start with `// Learning Goal: ...`.
    -   **Context**: Must include a `/* Context: ... */` block explaining the concept using clear analogies (no fictional roleplay).
    -   **Marker**: Must contain `// I AM NOT DONE` (unless it is a solution file, which are not currently in the repo).
    -   **TODOs**: Use `// TODO:` comments to guide the user.

3.  **Naming Conventions**:
    -   Files: `XX_descriptive_name.c` (e.g., `01_entry_point.c`).
    -   `info.toml` names: Unique, alphanumeric + underscores.

4.  **Content Rules**:
    -   **Bitwise**: Use `unsigned int` for bitwise operations. Use `#define` for flags (powers of 2).
    -   **File I/O**: Use `/tmp/` for file operations.
    -   **Math**: Avoid `<math.h>` and `sqrt` if possible. Use integer arithmetic.
    -   **Printing**: No prompts (e.g., "Enter number: ") if `stdin` is used.
    -   **Types**: Use `size_t` with `%zu`.
    -   **Arrays**: Demonstrate array decay explicitly if relevant.

5.  **Configuration (`info.toml`)**:
    -   `mode = "run"` is preferred.
    -   `output` must match exactly.
    -   `hint` should be helpful but not a giveaway.

## Verification Scripts

Run these commands to verify quality:

```bash
# Check for missing Learning Goal
grep -L "^// Learning Goal:" exercises/**/*.c

# Check for missing I AM NOT DONE marker
grep -L "// I AM NOT DONE" exercises/**/*.c

# Check for trailing whitespace
find exercises -name "*.c" -print0 | xargs -0 egrep -l " +$"

# Check for files not ending in newline
find exercises -name "*.c" -print0 | xargs -0 -I {} sh -c 'test -z "$(tail -c 1 "{}")" || echo "{}"'

# Check for Tab characters
grep -l $'\t' exercises/**/*.c
```
