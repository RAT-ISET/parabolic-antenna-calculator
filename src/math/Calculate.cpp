// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/math/Calculate.cpp
// Calculate the antenna parameter.

#include <pac/math/Calculate.hpp>
#include <pac/math/Function.hpp>

void Calculator::filledParameters(const size_t parameter_index)
{
    for (size_t parameter_linker_index = PARAMETER_INDEX.offset_[parameter_index]; parameter_linker_index < PARAMETER_INDEX.offset_[parameter_index + 1]; parameter_linker_index++)
    {
        functions_[PARAMETER_INDEX.linker_[parameter_linker_index]] -= 1;
        logger.debug(format("[math/Calculate.cpp:reduceFunctions] Function {} == {}", PARAMETER_INDEX.linker_[parameter_linker_index], functions_[PARAMETER_INDEX.linker_[parameter_linker_index]]));
    }
    empty_parameter_count_ -= 1;
}

Calculator::Calculator(ParameterList& list) : list_(list)
{
    logger.debug("[math/Calculate.cpp:Calculator] Calculator entry was created");
    for (size_t parameter_index = 0; parameter_index < list_.size(); parameter_index++)
    {
        if (list_[parameter_index].has_value())
        {
            logger.debug(format("[math/Calculate.cpp:Calculator] Find value at parameter {}", PARAMETER_MAP[parameter_index]));
            filledParameters(parameter_index);
        }
    }
}

optional<AntennaEntryError> Calculator::step()
{
    logger.debug("[math/Calculate.cpp:step] Calculator entry step");
    for (size_t function_index = 0; function_index < functions_.size(); function_index++)
    {
        if (functions_[function_index] == 1)
        {
            logger.debug(format("[math/Calculate.cpp:step] Find value can be calculated at function {}", function_index));
            for (size_t function_linker_index = FUNCTION_INDEX.offset_[function_index]; function_linker_index < FUNCTION_INDEX.offset_[function_index + 1]; function_linker_index++)
            {
                if (const size_t parameter_index = FUNCTION_INDEX.linker_[function_linker_index]; !list_[parameter_index].has_value())
                {
                    logger.debug(format("[math/Calculate.cpp:step] Find value can be calculated at parameter {}", PARAMETER_MAP[parameter_index]));
                    expected<double, AntennaEntryError> result;
                    switch (function_index)
                    {
                    case 0:
                        result = Functions::CalculateDiameter(parameter_index, list_);
                        break;
                    case 1:
                        result = Functions::CalculateWavelength(parameter_index, list_);
                        break;
                    case 2:
                        result = Functions::CalculateHeight(parameter_index, list_);
                        break;
                    case 3:
                        result = Functions::CalculateIncrease(parameter_index, list_);
                        break;
                    default:
                        result = unexpected(AntennaEntryError
                            (AntennaEntryErrorEnum::UnknownError, LogEntry()));
                    }
                    if (!result.has_value()) return result.error();
                    logger.debug(format("[math/Calculate.cpp:step] Calculate the value {:.3f} at parameter {}", result.value(), PARAMETER_MAP[parameter_index]));
                    list_[parameter_index] = result.value();
                    filledParameters(parameter_index);
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
