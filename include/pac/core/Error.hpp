// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/core/Error.hpp
// Header file of the antenna calculater error.

#pragma once
#include <pac/core/Logger.hpp>

using namespace std;

enum class AntennaEntryErrorEnum
{
    MissingParameter,
    InvalidParameter,
    ConflictParameter,
    UnknownParameter,
};

struct AntennaEntryError
{
    AntennaEntryErrorEnum type_;
    Logger log_;
    AntennaEntryError();
};