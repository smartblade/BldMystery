"""Run a build and fail on warnings which are not allowed.

Usage:
    python tools/check_warnings.py ALLOWED_FILE COMMAND [ARG...]

Runs COMMAND, prints its output as it goes and collects the warnings of the
compiler, the assembler and the linker ('warning C4996', 'warning A4011',
'warning LNK4217'). Exits with the exit code of COMMAND if it fails, with
code 1 if there are warnings whose numbers are not listed in ALLOWED_FILE
(one number per line, '#' starts a comment), and with code 0 otherwise.
Allowed warnings stay in the output as warnings.

Works with Python 2.7 and Python 3.
"""

from __future__ import print_function

import re
import subprocess
import sys

warning_regexp = re.compile(r'\bwarning (?P<number>(?:C|A|LNK)\d{4})\b')


def read_allowed(file_name):
    allowed = set()
    with open(file_name) as f:
        for line in f:
            number = line.split("#", 1)[0].strip()
            if number:
                allowed.add(number)
    return allowed


def main():
    if len(sys.argv) < 3:
        print(__doc__.strip())
        return 2
    allowed = read_allowed(sys.argv[1])
    process = subprocess.Popen(
        sys.argv[2:], stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
        universal_newlines=True)
    not_allowed = []
    for line in iter(process.stdout.readline, ""):
        sys.stdout.write(line)
        sys.stdout.flush()
        match = warning_regexp.search(line)
        if match and match.group("number") not in allowed:
            not_allowed.append(line.rstrip())
    process.stdout.close()
    result = process.wait()
    if result != 0:
        return result
    if not_allowed:
        print()
        print("Warnings which are not allowed ({}):".format(len(not_allowed)))
        for line in not_allowed:
            print(line)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
