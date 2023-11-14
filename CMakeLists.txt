cmake_minimum_required(VERSION 3.27)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

set(CMAKE_CXX_STANDARD 20)

cmake_policy(SET CMP0048 NEW)

project(
  plant
  DESCRIPTION "Python Library for Autonomous Navigation and Tracking"
  LANGUAGES C CXX
)

add_subdirectory(extern/pybind11)

pybind11_add_module(
  core
  ${CMAKE_SOURCE_DIR}/src/core/core.cc
  ${CMAKE_SOURCE_DIR}/src/core/transforms.cc
)
