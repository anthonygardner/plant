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

add_subdirectory(extern/googletest)
add_subdirectory(extern/pybind11)

pybind11_add_module(
  _plant
  ${CMAKE_SOURCE_DIR}/src/plant.cc
  ${CMAKE_SOURCE_DIR}/src/core/transforms.cc
  ${CMAKE_SOURCE_DIR}/src/sensors/imu.cc
)

#===============================================================================
# googletest

enable_testing()

add_executable(
  v3f_test
  ${CMAKE_SOURCE_DIR}/tests/v3f_test.cc
  ${CMAKE_SOURCE_DIR}/src/core/transforms.cc
)

target_link_libraries(
  v3f_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(v3f_test)
