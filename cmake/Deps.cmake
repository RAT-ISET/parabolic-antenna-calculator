include(FetchContent)

FetchContent_Declare(
        CLI11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG v2.6.2
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(CLI11)

add_library(ParabolicAntennaCalculatorDeps INTERFACE)
target_link_libraries(ParabolicAntennaCalculatorDeps INTERFACE CLI11::CLI11)
