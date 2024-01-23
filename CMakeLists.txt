cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE Debug)

cmake_policy(SET CMP0048 NEW)

project(
  plant
  DESCRIPTION "Python Library for Autonomous Navigation and Tracking"
  LANGUAGES C CXX
)

#===============================================================================
# external packages

add_subdirectory(extern/googletest)
add_subdirectory(extern/raylib)
add_subdirectory(extern/pybind11)
add_subdirectory(extern/yaml-cpp)

set(raylib_DIR "${CMAKE_SOURCE_DIR}/extern/raylib/cmake")
set(yaml-cpp_DIR "{CMAKE_SOURCE_DIR}/extern/yaml-cpp")

if (NOT TARGET raylib)
    find_package(raylib REQUIRED)
endif()

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

include_directories(${Python3_INCLUDE_DIRS})
include_directories(${pybind11_INCLUDE_DIR})

if (NOT TARGET yaml-cpp)
    find_package(yaml-cpp REQUIRED)
endif()

include_directories(${YAML_CPP_INCLUDE_DIRS})

#===============================================================================
# build plant

set(SOURCES ${CMAKE_SOURCE_DIR}/src/plant.cc)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${Python3_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${YAML_CPP_LIBRARIES})

pybind11_add_module(
  _plant
  ${CMAKE_SOURCE_DIR}/src/plant.cc
  ${CMAKE_SOURCE_DIR}/src/core/transforms.cc
  ${CMAKE_SOURCE_DIR}/src/sensors/imu.cc
)

target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} yaml-cpp)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

#===============================================================================
# build examples

add_subdirectory(examples/raylib)

#===============================================================================
# build googletest

enable_testing()

#add_executable(
#  parser_test
#  ${CMAKE_SOURCE_DIR}/tests/parser_test.cc
#  ${CMAKE_SOURCE_DIR}/src/utils/parser.cc
#)

#target_link_libraries(
#  parser_test
#  PRIVATE
#  GTest::gtest_main
#  GTest::gmock_main
#  ${YAML_CPP_LIBRARIES}
#)

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

#gtest_discover_tests(parser_test)
gtest_discover_tests(v3f_test)
