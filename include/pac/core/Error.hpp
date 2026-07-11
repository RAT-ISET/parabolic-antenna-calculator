// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/core/Error.hpp
// Header file of the antenna calculator error.

#pragma once
#include <pac/core/Logger.hpp>
#include <string_view>
#include <array>

using namespace std;

enum class AntennaEntryErrorEnum
{
    MissingParameter = 0,
    InvalidParameter = 1,
    ConflictParameter = 2,
    MathematicalError = 3,
    ErrorInputParameter = 4,
    UnknownParameter = 5,
    UnknownError = 6,
};

constexpr array<string_view, 7> ANTENNA_ENTRY_ERROR_MESSAGES = {
    "MissingParameter",
    "InvalidParameter",
    "ConflictParameter",
    "MathematicalError",
    "ErrorInputParameter",
    "UnknownParameter",
    "UnknownError",
};

struct AntennaEntryError
{
    AntennaEntryErrorEnum type_{};
    LogEntry log_;
    AntennaEntryError() = default;
    constexpr AntennaEntryError(AntennaEntryErrorEnum type, const LogEntry& log)
        : type_(type)
        , log_(log) {}
    [[nodiscard]] string_view getMessage() const;
};
