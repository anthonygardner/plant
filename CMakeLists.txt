cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_PYTHON_API "Build Python API using pybind11" ON)
option(BUILD_CXX_TESTS "Build C++ unit tests" OFF)

cmake_policy(SET CMP0048 NEW)

project(
  plant
  VERSION 0.0.1
  DESCRIPTION "Python Library for Autonomous Navigation and Tracking (PLANT)"
  LANGUAGES CXX
)

#==================================================
# Set up include directories
#==================================================

set(PLANT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${PLANT_INCLUDE_DIR})

#==================================================
# External dependencies
#==================================================

add_subdirectory(extern/googletest EXCLUDE_FROM_ALL)
add_subdirectory(extern/pybind11)

set(pybind11_DIR "${PROJECT_SOURCE_DIR}/extern/pybind11")
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

include_directories(${pybind11_INCLUDE_DIR})
include_directories(${Python3_INCLUDE_DIRS})

#==================================================
# Build plant
#==================================================

add_library(plant_math STATIC)
target_sources(plant_math PRIVATE
    src/math/quaternion.cpp
    src/math/vector.cpp
)
target_include_directories(plant_math PUBLIC ${PLANT_INCLUDE_DIR})

add_library(plant_filters STATIC)
target_sources(plant_filters PRIVATE
    src/filters/kalman_filter.cpp
    src/filters/extended_kalman_filter.cpp
)
target_include_directories(plant_filters PUBLIC ${PLANT_INCLUDE_DIR})

add_library(plant_core STATIC)
target_sources(plant_core PRIVATE
    src/core/transforms.cpp
)
target_include_directories(plant_core PUBLIC ${PLANT_INCLUDE_DIR})
target_link_libraries(plant_core PUBLIC plant_math)
target_link_libraries(plant_core PUBLIC plant_filters)

add_library(plant_sensors STATIC)
target_sources(plant_sensors PRIVATE
    src/sensors/imu.cpp
)
target_include_directories(plant_sensors PUBLIC ${PLANT_INCLUDE_DIR})
target_link_libraries(plant_sensors PUBLIC plant_core)

#==================================================
# Build Python API
#==================================================

if(BUILD_PYTHON_API)
    pybind11_add_module(_plant
        src/python/plant.cpp
    )

    target_include_directories(_plant PRIVATE ${PLANT_INCLUDE_DIR})

    target_link_libraries(_plant PRIVATE
        plant_math
        plant_core
        plant_sensors
    )
endif()

set_target_properties(_plant PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/api/plant
)

#==================================================
# Build C++ unit tests
#==================================================

if(BUILD_CXX_TESTS)
    enable_testing()

    add_executable(v3f_test
        tests/v3f_test.cpp
        src/core/transforms.cpp
    )

    target_link_libraries(
        v3f_test
        GTest::gtest_main
    )

    include(GoogleTest)

    gtest_discover_tests(v3f_test)
endif()
