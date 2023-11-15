#!/usr/bin/env bash

set -eou pipefail

readonly CWD=$(realpath .)
readonly TESTS_DIR=$(realpath $CWD/tests)

python3 -m pytest $TESTS_DIR/test_imports.py
