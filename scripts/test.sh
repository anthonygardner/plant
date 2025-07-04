#!/usr/bin/env bash

set -eou pipefail

readonly CWD=$(realpath .)
readonly TESTS_DIR=$(realpath $CWD/tests)
readonly VENV_DIR=$(realpath $CWD/.venv)

uv run pytest $TESTS_DIR
