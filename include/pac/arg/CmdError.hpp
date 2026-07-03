// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/arg/CmdError.hpp
// Header file of the error for command line.

#pragma once

#include <string>
#include <array>

using namespace std;

constexpr array<string_view, 4> error_messages {
    "The input argument was invalid",
    "The subcommand not found",
    "The parameter name not found",
    "The input out of range",
};

enum class CmdErrorEnum
{
    InvalidArgument = 0,
    UnknownCommand = 1,
    UnmatchParameter = 2,
    OutOfRange = 3,
};

struct CmdError
{
    CmdErrorEnum type_;
    string input_;
    [[nodiscard]] string getMessage() const;
};
