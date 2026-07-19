// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /test/CalculatorTest.cpp
// Calculator tester.

#include <expected>
#include <pac/core/Definition.hpp>
#include <pac/math/Function.hpp>

int main()
{
    ParameterList parameters;

    parameters[3] = 1;
    parameters[5] = 2;
    if (!Functions::CalculateDiameter(7, parameters).has_value() || parameters[7] != 2)
        return 1;
    return 0;
}

