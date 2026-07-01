// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /src/arg/Cmd.cpp
// Command line handler.

#include <iostream>

#include <CLI/CLI.hpp>
#include <pac/arg/Cmd.hpp>

using namespace std;

int command(const int argc, char* argv[])
{
    CLI::App app("Parabolic Antenna Calculater");

    app.set_version_flag(
        "-v,--version",
        "Parabolic Antenna Calculater Version 0.1.0"
    );

    app.footer(
        R"(Copyright (c) 2026 Team ISET
        License: MIT
        https://github.com/RAT-ISET/parabolic-antenna-calculater
    )");

    CLI11_PARSE(app, argc, argv);

    return EXIT_SUCCESS;
}
