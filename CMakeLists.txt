cmake_minimum_required(VERSION 3.21)

project(ParabolicAntennaCalculator C CXX)

set(CMAKE_CXX_STANDARD 23)

set(PROJECT_VERSION 0.1.0)
set(PROJECT_RELEASE 1)
set(PROJECT_DESCRIPTION "A parabolic antenna calculator")

include(cmake/Deps.cmake)
include(cmake/Release.cmake)

add_subdirectory(src)
