// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/core/Entry.hpp
// Header file of the entry for antenna.

#pragma once

#include <array>
#include <optional>
#include <expected>
#include <pac/core/Logger.hpp>
#include <pac/core/Error.hpp>
#include <pac/core/Definition.hpp>

using namespace std;

struct AntennaEntry
{
    ParameterList parameter_;
    AntennaEntry() = default;
    void addParameter(size_t index, double value);
    [[nodiscard]] expected<AntennaEntry, AntennaEntryError> calculate(AntennaEntry antenna) const;
};

struct AntennaEntryCalculate
{
    AntennaEntry data_;
    Logger logger_;
    expected<size_t, AntennaEntryErrorEnum> step(size_t index);
};
