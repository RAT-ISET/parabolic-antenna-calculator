// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/core/Entry.cpp
// Entry for antenna.

#include <pac/core/Entry.hpp>

void AntennaEntry::addParameter(const size_t index, double value)
{
    this->parameter_[index] = value;
}
