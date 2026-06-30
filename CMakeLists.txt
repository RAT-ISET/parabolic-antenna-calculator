cmake_minimum_required(VERSION 3.21)

project(ParabolicAntennaCalculater C CXX)

set(CMAKE_CXX_STANDARD 20)

include(cmake/Deps.cmake)

add_subdirectory(src)
