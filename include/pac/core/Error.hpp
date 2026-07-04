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
    MissingParameter,
    InvalidParameter,
    ConflictParameter,
    MathematicalError,
    UnknownParameter,
    ErrorInputParameter,
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