#!/usr/bin/env bash

set -eou pipefail

readonly CWD=$(realpath .)
readonly API_DIR=$(realpath $CWD/plant)
readonly BUILD_DIR=$(realpath $CWD/build)

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

mv $BUILD_DIR/*.so $API_DIR/core.so

python3 -m pip install -r $CWD/requirements.txt && python3 -m pip install $CWD