cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/out/install)

project(ParabolicAntennaCalculator C CXX)

set(PROJECT_VERSION 0.1.0)
if (PROJECT_FULL_VERSION)
    include(cmake/Version.cmake)
    get_short_version("${PROJECT_FULL_VERSION}" PROJECT_VERSION)
else ()
    set(PROJECT_FULL_VERSION ${PROJECT_VERSION})
endif ()

set(PROJECT_RELEASE 1)
set(PROJECT_DESCRIPTION "A parabolic antenna calculator")

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/out/dist")
include(cmake/Deps.cmake)
include(cmake/Release.cmake)
include(cmake/ArchPkg.cmake)

add_subdirectory(src)
