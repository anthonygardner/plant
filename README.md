# plant

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

## Overview

`plant` is a Python Library for Autonomous Navigation and Tracking research.

> [!NOTE]
> This repository is currently under construction.

![Alt](https://repobeats.axiom.co/api/embed/7b396ab12aae81b774176805c20b9f1be8827ccb.svg "Repobeats analytics image")

## Builds

##### C++

```shell
git submodule update --init --recursive
cmake -S . -B build
cmake --build build --target install
```

or

```shell
make build.cpp
```

##### Python

```shell
uv venv
uv pip install -r requirements.txt
uv pip install -e .
```

or

```shell
make build.python
```

## Unit Tests

##### C++

```shell
make test.cpp
```

##### Python

```shell
make test.python
```

## Scratchpad

```shell
make notebook
```
