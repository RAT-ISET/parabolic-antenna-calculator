// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/math/Calculate.hpp
// Header file of the calculator for the antenna parameter.

#pragma once

#include <expected>
#include <pac/core/Definition.hpp>
#include <pac/core/Error.hpp>
#include <pac/math/Function.hpp>

struct CalculateFunction;

class Calculator
{
    ParameterList list_;
public:
    explicit Calculator(ParameterList& list);
    void step();
    void step(size_t count);
    void run();
};