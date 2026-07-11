// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/math/Calculate.hpp
// Header file of the calculator for the antenna parameter.

#pragma once

#include <expected>
#include <array>
#include <pac/core/Definition.hpp>
#include <pac/core/Error.hpp>
#include <pac/math/IndexList.hpp>

using namespace std;

constexpr array<size_t, 4> FUNCTION_COUNT_LIST = {3, 2, 3, 4};
constexpr IndexList<8, 12> PARAMETER_INDEX(tuple{
    to_array<size_t>({1}),
    to_array<size_t>({1, 3}),
    to_array<size_t>({3}),
    to_array<size_t>({0, 2, 3}),
    to_array<size_t>({3}),
    to_array<size_t>({0, 2}),
    to_array<size_t>({2}),
    to_array<size_t>({0}),
});
constexpr IndexList<4, 12> FUNCTION_INDEX(tuple{
    to_array<size_t>({3, 5, 7}),
    to_array<size_t>({0, 1}),
    to_array<size_t>({3, 5, 6}),
    to_array<size_t>({1, 2, 3, 4}),
});

class Calculator
{
    ParameterList& list_;
    array<size_t, 4> functions_ = FUNCTION_COUNT_LIST;
    size_t empty_parameter_count_ = 8;
    void filledParameters(size_t parameter_index);
public:
    explicit Calculator(ParameterList& list);
    optional<AntennaEntryError> step();
    optional<AntennaEntryError> step(size_t count);
    optional<AntennaEntryError> run();
};
