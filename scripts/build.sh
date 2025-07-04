#!/usr/bin/env bash

set -eou pipefail

readonly CWD=$(realpath .)
readonly API_DIR=$(realpath $CWD/api/plant)
readonly BUILD_DIR=$(realpath $CWD/build)
readonly VENV_DIR=$(realpath $CWD/.venv)

git submodule update --init --recursive

if [ -e "$API_DIR/_plant.so" ]; then
  rm $API_DIR/_plant.so
fi

if [ -d "$BUILD_DIR" ]; then
  rm -fr $BUILD_DIR
fi

mkdir -p $BUILD_DIR && cd $BUILD_DIR

if [ "$(pwd)" != "$BUILD_DIR" ]; then
  echo -e "CRIT: Not in build/ directory!"
  exit 1
else
  cmake .. && cmake --build . -j 16
fi

mv $BUILD_DIR/_plant*.so $API_DIR/_plant.so

if [ -d "$VENV_DIR" ]; then
    rm -rf $VENV_DIR
fi

uv venv --python 3.11 && source $VENV_DIR/bin/activate
uv pip install -r $CWD/requirements.txt
uv pip install -e $CWD
