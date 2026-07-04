// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/core/Error.hpp
// Header file of the antenna calculator error.

#pragma once
#include <pac/core/Logger.hpp>

using namespace std;

enum class AntennaEntryErrorEnum
{
    MissingParameter = -1,
    InvalidParameter = -2,
    ConflictParameter = -3,
    MathematicalError = -4,
    ErrorInputParameter = -5,
    UnknownParameter = -101,
    UnknownError = -102,
};

struct AntennaEntryError
{
    AntennaEntryErrorEnum type_;
    LogEntry log_;
    AntennaEntryError() = default;
    constexpr AntennaEntryError(AntennaEntryErrorEnum type, const LogEntry& log)
        : type_(type)
        , log_(log) {}
};