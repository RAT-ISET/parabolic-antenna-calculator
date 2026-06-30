include(FetchContent)

FetchContent_Declare(
        tomlplusplus
        GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
        GIT_TAG v3.4.0
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(tomlplusplus)

add_library(ParabolicAntennaCalculaterDeps INTERFACE)
target_link_libraries(ParabolicAntennaCalculaterDeps INTERFACE tomlplusplus::tomlplusplus)
