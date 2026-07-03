// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/core/Entry.hpp
// Header file of the entry for antenna.

#pragma once

#include <string>

using namespace std;

constexpr string_view HELP_FOOTER =
    R"(Copyright (c) 2026 Team ISET
        License: MIT
        https://github.com/RAT-ISET/parabolic-antenna-calculator
    )";

constexpr string_view PARA_HELP_FOOTER =
    R"(Parameter List
        frequency
        wavelength
        efficiency
        diameter
        increase
        focalLength
        height
        f/D

        Copyright (c) 2026 Team ISET
        License: MIT
        https://github.com/RAT-ISET/parabolic-antenna-calculator
    )";
