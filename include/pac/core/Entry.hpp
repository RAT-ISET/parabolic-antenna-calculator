// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /include/pac/core/Entry.cpp
// Header file of the entry for antenna.

#pragma once

#include <array>
#include <optional>
#include <expected>
#include <pac/core/Logger.hpp>
#include <pac/core/Error.hpp>

using namespace std;

constexpr array parameter_map{
    "frequency",
    "wavelength",
    "efficiency",
    "diameter",
    "increase",
    "focalLength",
    "height",
    "f/D",
};

struct AntennaEntry
{
    array<optional<double>, 8> parameter_;
    AntennaEntry() = default;
    [[nodiscard]] expected<AntennaEntry, AntennaEntryError> calculate(AntennaEntry antenna) const;
};

struct AntennaEntryCalculate
{
    AntennaEntry data_;
    Logger logger_;
    expected<size_t, AntennaEntryErrorEnum> step(size_t index);
};
