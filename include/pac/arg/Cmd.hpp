// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /include/pac/arg/Cmd.hpp
// Header file of the command line handler.

#pragma once

#include <string>
#include <expected>
#include <pac/arg/CmdError.hpp>

using namespace std;

int command(int argc, char* argv[]);

expected<size_t, CmdError> matchName(const string& name);
expected<double, CmdError> matchValue(const string& value);
