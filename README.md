# plant

## Overview

`plant` is a Python Library for Autonomous Navigation and Tracking research.

> [!NOTE]
> This repository is currently under construction.

## Tech Stack

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

## Build Instructions

###### C++ 

```shell
cmake -S . -B build
cmake --build build --target install
```

###### Python bindings

```shell
./scripts/build.sh
```

## Running Tests / Examples

###### GoogleTest suite

```shell
cd build && ctest
```

###### Raylib example

```shell
cd build/examples/raylib
./raylib_example
```

###### pytest

```shell
./scripts/test.sh
```
