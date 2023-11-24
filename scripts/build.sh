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

python3.12 -m venv $VENV_DIR && source $VENV_DIR/bin/activate
python3 -m pip install --upgrade build pip setuptools
python3 -m pip install -r $CWD/requirements.txt
python3 -m build $CWD && python3 -m pip install $CWD

gcc $CWD/src/cli.c -o $VENV_DIR/bin/plant-cli
