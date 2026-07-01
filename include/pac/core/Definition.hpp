// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /include/pac/core/Entry.hpp
// Header file of the entry for antenna.

#pragma once

#include <array>

using namespace std;

using ParameterList = array<optional<double>, 8>;

constexpr array PARAMETER_MAP{
    "frequency",
    "wavelength",
    "efficiency",
    "diameter",
    "increase",
    "focalLength",
    "height",
    "f/D",
};
