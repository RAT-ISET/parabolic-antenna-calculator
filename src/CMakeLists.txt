add_executable(ParabolicAntennaCalculator Main.cpp)

target_include_directories(ParabolicAntennaCalculator PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ParabolicAntennaCalculator PRIVATE ParabolicAntennaCalculatorDeps ParabolicAntennaCalculatorCore ParabolicAntennaCalculatorArg)

include(GNUInstallDirs)

install(TARGETS ParabolicAntennaCalculator RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

add_subdirectory(core)
add_subdirectory(io)
add_subdirectory(arg)
add_subdirectory(math)
