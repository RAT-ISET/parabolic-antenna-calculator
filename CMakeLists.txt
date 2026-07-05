cmake_minimum_required(VERSION 3.21)

project(ParabolicAntennaCalculator VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

include(cmake/Deps.cmake)
include(cmake/Release.cmake)

add_subdirectory(src)
