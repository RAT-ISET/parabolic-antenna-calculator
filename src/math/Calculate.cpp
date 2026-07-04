// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/math/Calculate.cpp
// Calculate the antenna parameter.

#include <pac/math/Calculate.hpp>
#include <pac/math/Function.hpp>

Calculator::Calculator(ParameterList& list) : list_(list)
{
    logger.debug("[math/Calculate.cpp:Calculator] Calculator entry was created");
    for (size_t i = 0; i < list_.size(); i++)
    {
        if (list_[i].has_value())
        {
            logger.debug(format("[math/Calculate.cpp:Calculator] Find value at location {}", i));
            for (size_t j = PARAMETER_LIST[i]; j < PARAMETER_LIST[i + 1]; j++)
                functions_[FUNCTION_LINKER[j]] -= 1;
            empty_parameter_count_ -= 1;
        }
    }
}

optional<AntennaEntryError> Calculator::step()
{
    logger.debug("[math/Calculate.cpp:step] Calculator entry step");
    for (size_t i = 0; i < functions_.size(); i++)
    {
        if (functions_[i] == 1)
        {
            logger.debug(format("[math/Calculate.cpp:step] Find value can be calculated at function {}", i));
            for (size_t j = FUNCTION_LIST[i]; j < FUNCTION_LIST[i + 1]; j++)
            {
                if (size_t linked_j = PARAMETER_LINKER[j]; !list_[linked_j].has_value())
                {
                    logger.debug(format("[math/Calculate.cpp:step] Find value can be calculated at location {}", linked_j));
                    expected<double, AntennaEntryError> result;
                    switch (i)
                    {
                    case 0:
                        result = Functions::CalculateDiameter(linked_j, list_);
                        break;
                    case 1:
                        result = Functions::CalculateWavelength(linked_j, list_);
                        break;
                    case 2:
                        result = Functions::CalculateHeight(linked_j, list_);
                        break;
                    case 3:
                        result = Functions::CalculateIncrease(linked_j, list_);
                        break;
                    default:
                        result = unexpected(AntennaEntryError
                            (AntennaEntryErrorEnum::UnknownError, LogEntry()));
                    }
                    if (!result.has_value()) return result.error();
                    logger.debug(format("[math/Calculate.cpp:step] Calculate the value {:.3f} at location {}", result.value(), linked_j));
                    list_[linked_j] = result.value();
                    for (size_t k = PARAMETER_LIST[j]; k < PARAMETER_LIST[j + 1]; k++)
                        functions_[FUNCTION_LINKER[k]] -= 1;
                    empty_parameter_count_ -= 1;
                    return nullopt;
                }
            }
            return AntennaEntryError
                (AntennaEntryErrorEnum::UnknownError, LogEntry());
        }
    }
    return AntennaEntryError
        (AntennaEntryErrorEnum::MissingParameter, LogEntry());
}

optional<AntennaEntryError> Calculator::step(size_t count)
{
    while (count > 0 && empty_parameter_count_ > 0)
    {
        if (auto result = step(); result.has_value())
            return result.value();
        count--;
    }
    return nullopt;
}

optional<AntennaEntryError> Calculator::run()
{
    return step(8);
}
