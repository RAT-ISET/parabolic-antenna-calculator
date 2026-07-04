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

constexpr array<size_t, 4> FUNCTION_COUNT_LIST = {3, 2, 3, 4};
constexpr array<size_t, 12> FUNCTION_LINKER = {1, 1, 3, 3, 0, 2, 3, 3, 0, 2, 2, 0};
constexpr array<size_t, 9> PARAMETER_LIST = {0, 1, 3, 4, 7, 8, 10, 11, 12};
constexpr array<size_t, 12> PARAMETER_LINKER = {3, 5, 7, 0, 1, 3, 5, 6, 1, 2, 3, 4};
constexpr array<size_t, 5> FUNCTION_LIST = {0, 3, 5, 8, 12};

class Calculator
{
    ParameterList& list_;
    array<size_t, 4> functions_ = FUNCTION_COUNT_LIST;
    size_t empty_parameter_count_ = 8;
public:
    explicit Calculator(ParameterList& list);
    optional<AntennaEntryError> step();
    optional<AntennaEntryError> step(size_t count);
    optional<AntennaEntryError> run();
};
