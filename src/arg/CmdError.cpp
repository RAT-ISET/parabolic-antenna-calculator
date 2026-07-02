// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /src/arg/CmdError.cpp
// Error for command line.

#include <pac/arg/CmdError.hpp>

string CmdError::getMessage() const
{
    const string_view message = error_messages[static_cast<int>(type_)];
    return string(message) + "\n" + "Input: " + input_;
}
