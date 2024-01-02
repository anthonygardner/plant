#!/usr/bin/env bash

set -eou pipefail

readonly CWD=$(realpath .)
readonly TESTS_DIR=$(realpath $CWD/tests)
readonly VENV_DIR=$(realpath $CWD/.venv)

source $VENV_DIR/bin/activate && python -m pytest $TESTS_DIR
