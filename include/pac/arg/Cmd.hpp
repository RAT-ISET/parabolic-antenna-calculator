// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/arg/Cmd.hpp
// Header file of the command line handler.

#pragma once

#include <string>
#include <expected>
#include <CLI/CLI.hpp>
#include <pac/arg/CmdError.hpp>
#include <pac/io/PacProject.hpp>

using namespace std;

int command(int argc, char* argv[]);
int shutdown(Project project);
int shutdown(Project project, int code);

array<optional<string>, 7> addParaOptions(CLI::App* app);

expected<size_t, CmdError> matchName(const string& name);
expected<double, CmdError> matchValue(const string& value);
expected<array<optional<double>, 7>, CmdError> matchValues(const array<optional<string>, 7>& values);
