import os
import re
import sys
import tomllib

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

    # Bitwise: Use unsigned int
    # We check if the file path contains "11_bitwise" (including challenge)
    if "11_bitwise" in filepath:
        if "unsigned int" not in content:
            issues.append("Bitwise exercise should use 'unsigned int'")

    # File I/O: Use /tmp/
    if "14_file_io" in filepath:
        if "/tmp/" not in content:
            issues.append("File I/O exercise should use '/tmp/' directory")

    # Math: No <math.h>
    if "<math.h>" in content:
        issues.append("Should not use <math.h>")

    # Missing Includes
    # Helper to check if TODO instructs to include header
    def has_include_todo():
        return any("include" in line.lower() or "header" in line.lower() for line in lines if "TODO" in line)

    if re.search(r'\bbool\b', content) and "<stdbool.h>" not in content:
        if not has_include_todo():
            issues.append("Uses 'bool' but missing <stdbool.h>")

    if (re.search(r'\bmalloc\b', content) or re.search(r'\bfree\b', content)) and "<stdlib.h>" not in content:
        if not has_include_todo():
            issues.append("Uses 'malloc'/'free' but missing <stdlib.h>")

    if (re.search(r'\bprintf\b', content) or re.search(r'\bfprintf\b', content)) and "<stdio.h>" not in content:
        if not has_include_todo():
            issues.append("Uses printf/fprintf but missing <stdio.h>")

    if re.search(r'\b(strlen|strcpy|strcmp|strcat)\b', content) and "<string.h>" not in content:
        if not has_include_todo():
            issues.append("Uses string functions but missing <string.h>")

    # Check sizeof formatting
    for i, line in enumerate(lines):
        if "printf" in line and "sizeof" in line and "%zu" not in line:
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
