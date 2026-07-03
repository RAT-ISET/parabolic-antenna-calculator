cmake_minimum_required(VERSION 3.21)

project(ParabolicAntennaCalculator C CXX)

set(CMAKE_CXX_STANDARD 23)

include(cmake/Deps.cmake)
include(cmake/Release.cmake)

add_subdirectory(src)
