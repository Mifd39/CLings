import os
import re
import sys
import tomllib

def remove_comments_and_strings(text):
    """Removes comments and strings from C code."""
    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE
    )
    return re.sub(pattern, " ", text)

def remove_comments(text):
    """Removes comments from C code but keeps strings."""
    def replacer(match):
        s = match.group(0)
        if s.startswith('/'):
            return " "
        else:
            return s
    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE
    )
    return re.sub(pattern, replacer, text)

def check_file(filepath):
    issues = []
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()
        lines = content.splitlines(keepends=True)

    # 1. Check Header
    if not content.startswith("// Learning Goal:"):
        issues.append("Missing '// Learning Goal:' header")

    # 2. Check Context Block
    if "/* Context:" not in content and "/*\n    Context:" not in content:
        # Check for regex match
        if not re.search(r'/\*\s*Context:', content, re.DOTALL):
            issues.append("Missing '/* Context:' block")

    # 3. Check Marker
    if "// I AM NOT DONE" not in content:
        issues.append("Missing '// I AM NOT DONE' marker")

    # 4. Check Trailing Whitespace
    for i, line in enumerate(lines):
        if line.rstrip('\n') != line.rstrip():
            issues.append(f"Trailing whitespace on line {i+1}")

    # 5. Check File Ending
    if content:
        if not content.endswith('\n'):
            issues.append("File does not end with a newline")
        elif content.endswith('\n\n'):
            issues.append("File ends with multiple newlines")

    # 6. Check Tabs
    if '\t' in content:
        issues.append("Contains tab characters")

    # 7. Check Indentation (Basic check for 4 spaces)
    for i, line in enumerate(lines):
        stripped = line.lstrip()
        indent = len(line) - len(stripped)
        if indent > 0 and indent % 4 != 0:
            if indent == 2:
                issues.append(f"Indentation seems to be 2 spaces on line {i+1}")

    # 8. Check TODO format
    for i, line in enumerate(lines):
        if "//" in line and "todo" in line.lower():
            if "// TODO:" not in line and "TODO:" not in line:
                if re.search(r'//\s*todo\b', line, re.IGNORECASE) and not re.search(r'//\s*TODO:', line):
                    issues.append(f"TODO format incorrect on line {i+1} (expected '// TODO:')")

    # 9. Content Rules

    # Pre-process content for checks
    code_only = remove_comments_and_strings(content)
    code_with_strings = remove_comments(content)

    # Check for leading zeros (excluding comments and strings)
    # Match a '0' followed by digits, but not '0' alone, and not part of '0x' or '0b'
    # We look for word boundary, 0, then [0-9].
    # But we must exclude '0x' or '0.123'.
    # Regex: \b0[0-9] matches '01', '00'.
    # Does it match 0x? No, x is not 0-9.
    # Does it match 0.1? No, . is not 0-9.
    # Does it match 0 itself? No, [0-9] requires a second digit.
    # We use negative lookbehind (?<!\.) to avoid matching decimals like 0.001 (where 00 is matched)
    if re.search(r'(?<!\.)\b0[0-9]', code_only):
        # Double check it's not octal intention? Rules say avoid unless specifically demonstrating.
        # But we can flag it.
        issues.append("Integer literal with leading zero found (potential octal confusion)")

    # Check for Crab Emoji (anywhere)
    if "🦀" in content:
        issues.append("Contains forbidden crab emoji 🦀")

    # Check for Hello World consistency
    # Look for "Hello World" or "Hello, World" variations in strings
    # We want strictly "Hello, World!"
    # Regex: Hello,? World!?
    # We iterate matches in code_with_strings
    hello_pattern = re.compile(r'Hello,? World!?', re.IGNORECASE)
    for match in hello_pattern.finditer(code_with_strings):
        s = match.group(0)
        if s != "Hello, World!":
             issues.append(f"Incorrect Hello World format: '{s}' (Expected 'Hello, World!')")

    # Check for interactive prompts if stdin is used
    # Heuristic: if scanf/fgets/getchar is used, look for printf("Enter...")
    if re.search(r'\b(scanf|fgets|getchar)\b', code_only):
        # Look for printf with "Enter "
        # We search in code_with_strings
        if re.search(r'printf\s*\(\s*".*Enter ', code_with_strings, re.IGNORECASE):
             issues.append("Interactive prompt detected ('Enter...') but stdin is used. Verify this is allowed.")

    # Bitwise: Use unsigned int
    if "11_bitwise" in filepath:
        if "unsigned int" not in code_only:
            issues.append("Bitwise exercise should use 'unsigned int'")

    # File I/O: Use /tmp/
    if "14_file_io" in filepath:
        if "/tmp/" not in content: # Check content to include strings
            issues.append("File I/O exercise should use '/tmp/' directory")

    # Math: No <math.h>
    if "<math.h>" in content: # Includes are usually not in strings/comments but could be commented out
        # Check code_only for #include <math.h>?
        # No, includes might be stripped by remove_comments_and_strings if they are treated as... wait.
        # remove_comments_and_strings handles // and /* */. Includes start with #.
        # But <math.h> might be seen as... it's not a string or comment.
        if "<math.h>" in code_only:
             issues.append("Should not use <math.h>")

    # Missing Includes
    def has_include_todo():
        return any("include" in line.lower() or "header" in line.lower() for line in lines if "TODO" in line)

    if re.search(r'\bbool\b', code_only) and "<stdbool.h>" not in code_only:
        if not has_include_todo():
            issues.append("Uses 'bool' but missing <stdbool.h>")

    if (re.search(r'\b(malloc|free|realloc|calloc)\b', code_only)) and "<stdlib.h>" not in code_only:
        if not has_include_todo():
            issues.append("Uses memory allocation functions but missing <stdlib.h>")

    if (re.search(r'\b(printf|fprintf)\b', code_only)) and "<stdio.h>" not in code_only:
        if not has_include_todo():
            issues.append("Uses printf/fprintf but missing <stdio.h>")

    if re.search(r'\b(strlen|strcpy|strcmp|strcat|strstr|strchr)\b', code_only) and "<string.h>" not in code_only:
        if not has_include_todo():
            issues.append("Uses string functions but missing <string.h>")

    # Check ctype functions
    ctype_funcs = r'\b(isalnum|isalpha|iscntrl|isdigit|isgraph|islower|isprint|ispunct|isspace|isupper|isxdigit|tolower|toupper)\b'
    if re.search(ctype_funcs, code_only) and "<ctype.h>" not in code_only:
        if not has_include_todo():
            issues.append("Uses ctype functions but missing <ctype.h>")

    # Check sizeof formatting
    # This checks lines individually which is safer for this specific check
    for i, line in enumerate(lines):
        if "printf" in line and "sizeof" in line and "%zu" not in line:
             # Check if it's commented out
             if not line.strip().startswith("//"):
                issues.append(f"Line {i+1}: sizeof used in printf without %zu")

    return issues

def check_info_toml():
    issues = []
    if not os.path.exists("info.toml"):
        return ["info.toml not found"]

    try:
        with open("info.toml", 'rb') as f:
            data = tomllib.load(f)
    except Exception as e:
        return [f"Error parsing info.toml: {e}"]

    exercises = data.get("exercises", [])
    if not exercises:
        issues.append("No exercises found in info.toml")

    # Gather all file paths from info.toml
    info_paths = set()
    info_names = set()

    for ex in exercises:
        name = ex.get("name")
        if not name:
            issues.append("Exercise missing 'name'")
        elif name in info_names:
            issues.append(f"Duplicate exercise name: {name}")
        else:
            info_names.add(name)

        if "path" not in ex:
            issues.append(f"Exercise {ex.get('name', 'Unknown')} missing 'path'")
            continue

        path = ex["path"]
        if path in info_paths:
            issues.append(f"Duplicate exercise path: {path}")
        info_paths.add(path)

        if not os.path.exists(path):
            issues.append(f"File listed in info.toml does not exist: {path}")

        if ex.get("mode") == "run":
            if "output" not in ex and "args" not in ex:
                issues.append(f"Exercise {ex.get('name', 'Unknown')} is mode='run' but has no 'output' or 'args' verification")

            # Check for Hello World output consistency
            output = ex.get("output", "")
            if "Hello" in output and "World" in output:
                 if "Hello, World!" not in output:
                     issues.append(f"Exercise {name} output contains 'Hello World' but not 'Hello, World!'")

        if "hint" not in ex:
            issues.append(f"Exercise {ex.get('name', 'Unknown')} missing 'hint'")

    # Gather all .c files in exercises/
    fs_paths = set()
    for dirpath, dirnames, filenames in os.walk("exercises"):
        for filename in filenames:
            if filename.endswith(".c"):
                # normalize path to match info.toml (unix style)
                rel_path = os.path.relpath(os.path.join(dirpath, filename), ".")
                rel_path = rel_path.replace("\\", "/")
                fs_paths.add(rel_path)

    # Check for files on FS not in info.toml
    for path in fs_paths:
        if path not in info_paths:
            issues.append(f"File found on filesystem but not in info.toml: {path}")

    return issues

def main():
    has_issues = False

    # Check info.toml
    print("Checking info.toml...")
    toml_issues = check_info_toml()
    if toml_issues:
        for issue in toml_issues:
            print(f"  - {issue}")
        has_issues = True
        print("-" * 20)
    else:
        print("info.toml looks good.")
        print("-" * 20)

    # Check files
    root_dir = 'exercises'
    print("Checking exercise files...")
    for dirpath, dirnames, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith('.c'):
                filepath = os.path.join(dirpath, filename)
                issues = check_file(filepath)
                if issues:
                    print(f"File: {filepath}")
                    for issue in issues:
                        print(f"  - {issue}")
                    has_issues = True
                    print("-" * 20)

    if has_issues:
        sys.exit(1)
    else:
        print("All checks passed. Quality verified.")

if __name__ == "__main__":
    main()
