"""Check and apply rules of docs/code-style.md to C++ sources.

Rules:
    pointer   '&' and '*' are attached to names, not to types:
              'const B_Vector &that', not 'const B_Vector& that'
    braces    opening braces are on separate lines

Usage:
    python tools/style.py check [--rule RULE] [--github] [PATH...]
    python tools/style.py fix --rule RULE [PATH...]

Options:
    --rule RULE   the rule to check or apply: pointer or braces ('check'
                  checks all rules without it, 'fix' requires it)
    --github      print violations as error annotations of GitHub Actions
                  ('::error file=FILE,line=LINE,title=RULE::MESSAGE')

'check' checks the rules one after another, prints the violations of each
rule as 'file:line: [rule] message' followed by the number of violations of
the rule, and exits with code 1 if there are violations. 'fix' applies one
rule to the files.
Without paths all sources of src are processed, except IGNORED_PATHS.
"""
import argparse
import os
import re
import sys
import traceback

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SOURCE_EXTENSIONS = (".c", ".cpp", ".h")

# Paths (relative to the repository, '/' separated) which are not checked:
# third party code, generated code and code with many violations
IGNORED_PATHS = [
    "src/Python-1.5.2",
    "src/BladeExt",
    "src/NetBlade",
    "src/netgame",
    "src/Raster/py_raster.cpp",
    "src/Raster/raster_device.cpp",
]
# Directories with generated code
IGNORED_DIRECTORY_NAMES = ["asm"]

RULES = ("pointer", "braces")

# Words after which '*' and '&' are operators of expressions
_EXPRESSION_KEYWORDS = {
    "return", "case", "sizeof", "delete", "throw", "operator", "else",
    "do",
}
_POINTER_REGEXP = re.compile(
    r"(?P<before>[\w>])(?P<ops>[*&]+)(?P<spaces>[ \t]+)(?=[A-Za-z_~(])")
_WORD_BEFORE_REGEXP = re.compile(r"(\w+)$")


class _Line:
    """A line of a source: text, line ending and code without comments,
    strings and preprocessor directives (replaced by spaces)."""

    def __init__(self, text, ending, code):
        self.text = text
        self.ending = ending
        self.code = code


def _read_lines(path):
    with open(path, "rb") as f:
        data = f.read().decode("latin-1")
    lines = []
    in_comment = False
    in_directive = False
    for match in re.finditer(r"([^\r\n]*)(\r\n|\n|\r|$)", data):
        text, ending = match.group(1), match.group(2)
        if not text and not ending:
            break
        code, in_comment, in_directive = _strip_line(
            text, in_comment, in_directive)
        lines.append(_Line(text, ending, code))
    return lines


def _strip_line(text, in_comment, in_directive):
    """Replace comments, strings, characters and preprocessor directives by
    spaces."""
    if in_directive or (not in_comment and text.lstrip().startswith("#")):
        return " " * len(text), in_comment, text.rstrip().endswith("\\")
    code = []
    i = 0
    while i < len(text):
        if in_comment:
            end = text.find("*/", i)
            if end < 0:
                code.append(" " * (len(text) - i))
                break
            code.append(" " * (end + 2 - i))
            i = end + 2
            in_comment = False
        elif text.startswith("/*", i):
            in_comment = True
            code.append("  ")
            i += 2
        elif text.startswith("//", i):
            code.append(" " * (len(text) - i))
            break
        elif text[i] in "\"'":
            quote = text[i]
            end = i + 1
            while end < len(text) and text[end] != quote:
                end += 2 if text[end] == "\\" else 1
            end = min(end + 1, len(text))
            code.append(quote + " " * (end - i - 2) + quote)
            i = end
        else:
            code.append(text[i])
            i += 1
    return "".join(code)[:len(text)].ljust(len(text)), in_comment, False


def _write_lines(path, lines):
    with open(path, "wb") as f:
        f.write("".join(
            line.text + line.ending for line in lines).encode("latin-1"))


# Rule 'pointer'

def _pointer_violations(line):
    """Positions of '*' and '&' attached to types in the code of the line."""
    result = []
    for match in _POINTER_REGEXP.finditer(line.code):
        ops = match.group("ops")
        if ops == "&&" or "&&" in ops:
            continue
        word = _WORD_BEFORE_REGEXP.search(line.code[:match.end("before")])
        if word is not None and (
            word.group(1) in _EXPRESSION_KEYWORDS or word.group(1).isdigit()
        ):
            continue
        result.append(match)
    return result


def _check_pointer(lines):
    for index, line in enumerate(lines):
        for match in _pointer_violations(line):
            yield index, "'{}' is attached to the type, not to the name".format(
                match.group("ops"))


def _fix_pointer(lines):
    for line in lines:
        matches = _pointer_violations(line)
        for match in reversed(matches):
            start = match.start("ops")
            end = match.end("spaces")
            line.text = (
                line.text[:start] + match.group("spaces") +
                match.group("ops") + line.text[end:])
            line.code = (
                line.code[:start] + match.group("spaces") +
                match.group("ops") + line.code[end:])
    return lines


# Rule 'braces'

def _opening_braces(lines):
    """Opening braces of blocks which are not on separate lines:
    (line index, column). Braces of initializers ('= {') and of
    'extern "C" {' are allowed."""
    stack = []
    result = []
    for index, line in enumerate(lines):
        code = line.code
        for column, char in enumerate(code):
            if char == "{":
                before = code[:column].rstrip()
                if (
                    before.endswith("=") or
                    (stack and stack[-1] == "initializer") or
                    before.endswith(",") or before.endswith("(")
                ):
                    stack.append("initializer")
                    continue
                stack.append("block")
                if re.match(r'\s*extern\s+"\s*"\s*$', code[:column]):
                    continue
                if before.strip() or code[column + 1:].strip():
                    result.append((index, column))
            elif char == "}" and stack:
                stack.pop()
    return result


def _check_braces(lines):
    for index, column in _opening_braces(lines):
        yield index, "'{' is not on a separate line"


def _fix_braces(lines):
    """Move opening braces to separate lines. A line with '}' before the
    statement ('} else {') is split at '}' too, a body on the same line as
    its braces ('{ return x; }') is moved to separate lines."""
    braces = {}
    for index, column in _opening_braces(lines):
        braces.setdefault(index, []).append(column)
    new_lines = []
    for index, line in enumerate(lines):
        if index not in braces or len(braces[index]) != 1:
            new_lines.append(line)
            continue
        split = _split_brace_line(line, braces[index][0])
        new_lines.extend(split if split is not None else [line])
    return new_lines


def _split_brace_line(line, column):
    indent = re.match(r"[ \t]*", line.text).group(0)
    unit = "    "
    text, code = line.text, line.code
    head = text[:column].rstrip()
    tail_code = code[column + 1:]
    tail = text[column + 1:]
    result = []
    head_code = code[:column]
    if head_code.strip().startswith("}") and head_code.strip() != "}":
        # '} else {'
        first = head_code.index("}")
        result.append(indent + "}")
        head = indent + text[first + 1:column].strip()
    elif head_code.strip() == "}":
        result.append(indent + "}")
        head = ""
    if head.strip():
        result.append(head)
    if not tail_code.strip():
        # Comment after '{' stays with the head
        comment = tail.strip()
        if comment and result:
            result[-1] += " " + comment
        elif comment:
            result.append(indent + comment)
        result.append(indent + "{")
    else:
        closing = tail_code.rfind("}")
        if closing < 0 or tail_code.count("{") or tail_code.count("}") != 1:
            return None
        body = tail[:closing].strip()
        after = tail[closing + 1:].strip()
        result.append(indent + "{")
        if body:
            result.append(indent + unit + body)
        result.append(indent + "}" + after)
    new_lines = []
    for text in result:
        new_line = _Line(text, line.ending, text)
        new_lines.append(new_line)
    # Code of new lines is recomputed by the next check
    return new_lines


_CHECKS = {"pointer": _check_pointer, "braces": _check_braces}
_FIXES = {"pointer": _fix_pointer, "braces": _fix_braces}


def _is_ignored(rel_path):
    parts = rel_path.split("/")
    if any(name in parts[:-1] for name in IGNORED_DIRECTORY_NAMES):
        return True
    return any(
        rel_path == ignored or rel_path.startswith(ignored + "/")
        for ignored in IGNORED_PATHS)


def _source_files(paths):
    if not paths:
        paths = [os.path.join(ROOT, "src")]
    for path in paths:
        if os.path.isfile(path):
            yield path
            continue
        for dirpath, dirs, files in os.walk(path):
            dirs.sort()
            for name in sorted(files):
                if not name.lower().endswith(SOURCE_EXTENSIONS):
                    continue
                file_path = os.path.join(dirpath, name)
                if _is_ignored(_relative(file_path)):
                    continue
                yield file_path


def _relative(path):
    return os.path.relpath(os.path.abspath(path), ROOT).replace(os.sep, "/")


def check(rules, paths, github):
    """Check the rules one after another: violations of each rule are printed
    together, followed by the number of violations of the rule. A failure of
    one rule doesn't stop checking of other rules."""
    files = [(path, _read_lines(path)) for path in _source_files(paths)]
    all_passed = True
    for rule in rules:
        if github:
            print("::group::{}".format(rule))
        num_violations = 0
        error = None
        try:
            for path, lines in files:
                for index, message in _CHECKS[rule](lines):
                    num_violations += 1
                    _print_violation(
                        _relative(path), index + 1, rule, message, github)
        except Exception:
            error = traceback.format_exc()
            print(error, end="")
        if github:
            print("::endgroup::")
        if error is not None:
            all_passed = False
            if github:
                print("::error title={}::rule failed: {}".format(
                    rule, error.strip().splitlines()[-1]))
            print("{}: failed".format(rule))
            continue
        if num_violations:
            all_passed = False
        print("{}: {} violation(s)".format(rule, num_violations))
    return all_passed


def _print_violation(rel_path, line_number, rule, message, github):
    if github:
        print("::error file={},line={},title={}::{}".format(
            rel_path, line_number, rule, message))
    else:
        print("{}:{}: [{}] {}".format(rel_path, line_number, rule, message))


def fix(rule, paths):
    num_files = 0
    for path in _source_files(paths):
        lines = _read_lines(path)
        if not list(_CHECKS[rule](lines)):
            continue
        _write_lines(path, _FIXES[rule](lines))
        num_files += 1
        remaining = list(_CHECKS[rule](_read_lines(path)))
        for index, message in remaining:
            print("{}:{}: [{}] not fixed: {}".format(
                _relative(path), index + 1, rule, message))
    print("{}: fixed {} file(s)".format(rule, num_files))


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("command", choices=("check", "fix"))
    parser.add_argument("--rule", choices=RULES)
    parser.add_argument(
        "--github", action="store_true",
        help="print violations as GitHub Actions annotations")
    parser.add_argument("paths", nargs="*")
    args = parser.parse_args()
    if args.command == "fix":
        if args.rule is None:
            parser.error("fix applies one rule, --rule is required")
        fix(args.rule, args.paths)
        return 0
    rules = [args.rule] if args.rule else list(RULES)
    return 0 if check(rules, args.paths, args.github) else 1


if __name__ == "__main__":
    sys.exit(main())
