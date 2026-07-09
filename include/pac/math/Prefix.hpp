// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/math/Prefix.hpp
// Function definition for calculator.

#pragma once
#include <string>
#include <format>

using namespace std;

constexpr string_view MIN_UNIT = "munpfazyrq";
constexpr string_view MAX_UNIT = "kMGTPEZYRQ";

constexpr string prefixFormat(double number)
{
    size_t count = 1;
    if (number >= 1000)
    {
        while (number >= 1000)
        {
            number /= 1000;
            count++;
        }
        return format("{:.4g} {}", number, MAX_UNIT[count]);
    }
    if (number <= 0.001)
    {
        while (number <= 0.001)
        {
            number *= 1000;
            count++;
        }
        return format("{:.4g} {}", number, MIN_UNIT[count]);
    }
    return format("{:.4g} ", number);
}
