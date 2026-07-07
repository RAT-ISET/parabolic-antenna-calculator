// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/core/Error.cpp
// Antenna calculator error.

#include <pac/core/Error.hpp>

string_view AntennaEntryError::getMessage() const
{
    return ANTENNA_ENTRY_ERROR_MESSAGES[static_cast<size_t>(type_)];
}
