cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE Debug)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

cmake_policy(SET CMP0048 NEW)

project(
  plant
  VERSION 1.0
  DESCRIPTION "Python Library for Autonomous Navigation and Tracking"
  LANGUAGES C CXX
)

#===============================================================================
# configure dependencies

add_subdirectory(extern/googletest EXCLUDE_FROM_ALL)
add_subdirectory(extern/raylib)
add_subdirectory(extern/pybind11)
add_subdirectory(extern/yaml-cpp)

set(pybind11_DIR "${PROJECT_SOURCE_DIR}/extern/pybind11")

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

include_directories(${pybind11_INCLUDE_DIR})
include_directories(${Python3_INCLUDE_DIRS})
include_directories(${YAML_CPP_INCLUDE_DIR})

#===============================================================================
# build plant

set(SOURCES ${PROJECT_SOURCE_DIR}/src/plant.cc)

add_library(
    ${PROJECT_NAME}
    STATIC
    ${SOURCES}
)

pybind11_add_module(
    _plant
    ${PROJECT_SOURCE_DIR}/src/plant.cc
    ${PROJECT_SOURCE_DIR}/src/core/transforms.cc
    ${PROJECT_SOURCE_DIR}/src/sensors/imu.cc
)

target_link_libraries(${PROJECT_NAME} ${Python3_LIBRARIES})

target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} yaml-cpp)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

target_link_libraries(_plant PRIVATE ${PROJECT_NAME})

#===============================================================================
# build examples

add_subdirectory(examples/raylib)

#===============================================================================
# build googletest

enable_testing()

add_executable(
  parser_test
  ${PROJECT_SOURCE_DIR}/tests/parser_test.cc
  ${PROJECT_SOURCE_DIR}/src/utils/parser.cc
)

target_link_libraries(
  parser_test
  GTest::gtest_main
  GTest::gmock_main
  yaml-cpp
)

add_executable(
  v3f_test
  ${PROJECT_SOURCE_DIR}/tests/v3f_test.cc
  ${PROJECT_SOURCE_DIR}/src/core/transforms.cc
)

target_link_libraries(
  v3f_test
  GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(parser_test)
gtest_discover_tests(v3f_test)
