// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/math/Function.hpp
// Function definition for calculator.

#pragma once

#include <cmath>
#include <numbers>
#include <pac/core/Error.hpp>
#include <pac/math/Constants.hpp>

constexpr optional<AntennaEntryErrorEnum> CheckInputParameterItem(const optional<double> parameter)
{
    if (!parameter.has_value()) return AntennaEntryErrorEnum::MissingParameter;
    if (parameter < 0) return AntennaEntryErrorEnum::InvalidParameter;
    return nullopt;
}

template<size_t N>
constexpr expected<LogEntry, AntennaEntryError> CheckInputParameter(const array<size_t, N>& unchecked_list, const ParameterList& list)
{
    LogEntry log_entry;
    log_entry.input_ = vector(unchecked_list.begin(), unchecked_list.end());
    for (const size_t i : unchecked_list)
    {
        if (optional<AntennaEntryErrorEnum> error_type = CheckInputParameterItem(list[i]); error_type.has_value())
            return unexpected(AntennaEntryError(error_type.value(), log_entry));
    }
    return log_entry;
}

constexpr double sq(const double x)
{
    return x * x;
}

constexpr auto UNMATCHED_INPUT_PARAMETER = AntennaEntryError(AntennaEntryErrorEnum::ErrorInputParameter, LogEntry());

namespace Functions
{
    constexpr expected<double, AntennaEntryError> CalculateDiameter
        (const size_t want, const ParameterList& list)
    {
        if (want == 3)
        {
            constexpr array<size_t, 2> unchecked_list = {5, 7};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return list[5].value() / list[7].value();
        }
        if (want == 5)
        {
            constexpr array<size_t, 2> unchecked_list = {3, 7};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return list[3].value() * list[7].value();
        }
        if (want == 7)
        {
            constexpr array<size_t, 2> unchecked_list = {3, 5};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return list[5].value() / list[3].value();
        }
        return unexpected(UNMATCHED_INPUT_PARAMETER);
    }

    constexpr expected<double, AntennaEntryError> CalculateWavelength
        (const size_t want, const ParameterList& list)
    {
        if (want == 0)
        {
            constexpr array<size_t, 1> unchecked_list = {1};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return Constants::C / list[1].value();
        }
        if (want == 1)
        {
            constexpr array<size_t, 1> unchecked_list = {};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return Constants::C / list[0].value();
        }
        return unexpected(UNMATCHED_INPUT_PARAMETER);
    }

    constexpr expected<double, AntennaEntryError> CalculateHeight
        (const size_t want, const ParameterList& list)
    {
        if (want == 3)
        {
            constexpr array<size_t, 2> unchecked_list = {5, 6};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return sqrt(16 * list[5].value() * list[6].value());
        }
        if (want == 5) {
            constexpr array<size_t, 2> unchecked_list = {3, 6};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return sq(list[3].value()) / (16 * list[6].value());
        }
        if (want == 6) {
            constexpr array<size_t, 2> unchecked_list = {3, 5};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return sq(list[3].value()) / (16 * list[3].value());
        }
        return unexpected(UNMATCHED_INPUT_PARAMETER);
    }

    constexpr expected<double, AntennaEntryError> CalculateIncrease
        (const size_t want, const ParameterList& list)
    {
        if (want == 1)
        {
            constexpr array<size_t, 3> unchecked_list = {2, 3, 4};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return pow(10, list[3].value()) * numbers::pi * sqrt(list[2].value() / list[4].value());
        }
        if (want == 2) {
            constexpr array<size_t, 3> unchecked_list = {1, 3, 4};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return list[4].value() * sq(list[1].value() / (numbers::pi * pow(10, list[3].value())));
        }
        if (want == 3) {
            constexpr array<size_t, 3> unchecked_list = {1, 2, 4};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return log10(list[1].value() * Constants::BACK_PI * sqrt(list[4].value() / list[2].value()));
        }
        if (want == 4) {
            constexpr array<size_t, 3> unchecked_list = {1, 2, 3};
            auto out = CheckInputParameter(unchecked_list, list);
            if (!out.has_value()) return unexpected(out.error());
            logger.addEntry(out.value());
            return list[2].value() * sq(numbers::pi * pow(10, list[3].value()) / list[1].value());
        }
        return unexpected(UNMATCHED_INPUT_PARAMETER);
    }
}
