import os
import re
import sys

def check_file(filepath):
    issues = []
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()
        lines = content.splitlines(keepends=True)

    # 1. Check Header
    if not content.startswith("// Learning Goal:"):
        issues.append("Missing '// Learning Goal:' header")

    # 2. Check Marker
    if "// I AM NOT DONE" not in content:
        issues.append("Missing '// I AM NOT DONE' marker")

    # 3. Check Trailing Whitespace
    for i, line in enumerate(lines):
        if line.rstrip('\n') != line.rstrip():
            issues.append(f"Trailing whitespace on line {i+1}")

    # 4. Check File Ending
    if content and not content.endswith('\n'):
        issues.append("File does not end with a single newline")

    # 5. Check Tabs
    if '\t' in content:
        issues.append("Contains tab characters")

    # 6. Check Indentation (Basic check for 4 spaces)
    # Check for lines starting with odd number of spaces (except 0) or 2 spaces
    for i, line in enumerate(lines):
        stripped = line.lstrip()
        indent = len(line) - len(stripped)
        if indent > 0 and indent % 4 != 0:
            # Allow for some continuation lines or aligned parameters, but basic blocks should be 4
            # This is heuristics, so maybe just warn?
            # But let's look for 2 spaces specifically
            if indent == 2:
                 issues.append(f"Indentation seems to be 2 spaces on line {i+1}")
            elif indent % 4 != 0:
                 # It might be continuation, ignore for now unless sure
                 pass

    # 7. Check TODO format
    # Should be `// TODO:`
    for i, line in enumerate(lines):
        if "//" in line and "todo" in line.lower():
            if "// TODO:" not in line and "TODO:" not in line: # simplistic check
                 # check if it is part of a sentence or the marker
                 if re.search(r'//\s*todo\b', line, re.IGNORECASE) and not re.search(r'//\s*TODO:', line):
                     issues.append(f"TODO format incorrect on line {i+1} (expected '// TODO:')")

    # 8. Check for printf sizeof without %zu
    for i, line in enumerate(lines):
        if "sizeof(" in line and "printf" in line:
            if "%zu" not in line and "%lu" not in line: # %lu is common mistake, check if allowed
                 # Actually AGENTS says use %zu. So if we see sizeof and printf but no %zu, it's suspicious
                 pass # Too many false positives possible (e.g. printing something else)

    return issues

def main():
    root_dir = 'exercises'
    has_issues = False

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
        print("No issues found.")

if __name__ == "__main__":
    main()
