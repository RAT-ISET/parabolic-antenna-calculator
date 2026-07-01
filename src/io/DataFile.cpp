// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /src/io/DataFile.cpp
// Reader and writer for data file.

#include <cstdint>
#include <pac/io/DataFile.hpp>

DataFile::DataFile(fstream file)
{
    this->file_ = std::move(file);
    uint8_t flag;
    file.read(reinterpret_cast<char*>(&flag), sizeof(uint8_t));

    for (int i = 7; i > 0; i--)
    {
        if (flag & 0x01)
        {
            double data;
            file.read(reinterpret_cast<char*>(&data), sizeof(double));
            this->parameters_[i] = data;
        } else
        {
            this->parameters_[i] = nullopt;
        }
    }
}

optional<double> DataFile::setParameter(const size_t index, double value)
{
    const auto old_value = parameters_[index];
    parameters_[index] = value;
    return old_value;
}

optional<double> DataFile::deleteParameter(const size_t index)
{
    const auto value = parameters_[index];
    parameters_[index] = nullopt;
    return value;
}

optional<double> DataFile::getParameter(const size_t index) const
{
    return parameters_[index];
}

ParameterList& DataFile::getParameterList()
{
    return parameters_;
}
