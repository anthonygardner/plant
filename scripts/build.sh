#!/usr/bin/env bash

set -eou pipefail

readonly CWD=$(realpath .)
readonly API_DIR=$(realpath $CWD/api/plant)
readonly BUILD_DIR=$(realpath $CWD/build)
readonly VENV_DIR=$(realpath $CWD/.venv)

git submodule update --init --recursive

if [ -e "$API_DIR/plant.so" ]; then
  rm $API_DIR/plant.so
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

mv $BUILD_DIR/*.so $API_DIR/_plant.so

if [ ! -d "$VENV_DIR" ]; then
  python3.12 -m venv $VENV_DIR
  python3.12 -m pip install -r $CWD/requirements.txt --target=$VENV_DIR/lib/python3.12/site-packages
fi

source $VENV_DIR/bin/activate && python3 -m pip install $CWD

gcc $CWD/src/cli.cc -o $VENV_DIR/bin/plant-cli
