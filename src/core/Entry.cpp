// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /src/core/Entry.cpp
// Entry for antenna.

#include <pac/core/Entry.hpp>

optional<size_t> matchParameter(const string& name)
{
    if (const auto parameter = ranges::find(PARAMETER_MAP, name); parameter == PARAMETER_MAP.end())
    {
        return nullopt;
    } else
    {
        auto index = distance(PARAMETER_MAP.begin(), parameter);
        return index;
    }
}

void AntennaEntry::addParameter(const size_t index, double value)
{
    this->parameter_[index] = value;
}

optional<size_t> AntennaEntry::addParameterByName(const string& name, double value)
{
    if (const auto index_optional = matchParameter(name); index_optional.has_value())
    {
        size_t index = index_optional.value();
        this->parameter_[index] = value;
        return index;
    }
    return nullopt;
}
