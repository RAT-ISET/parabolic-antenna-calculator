// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/io/DataFile.cpp
// Reader and writer for data file.

#include <cstdint>
#include <pac/io/DataFile.hpp>

DataFile::DataFile(fstream file)
{
    file_ = std::move(file);
    uint8_t flag;
    file.read(reinterpret_cast<char*>(&flag), sizeof(uint8_t));

    for (int i = 7; i > 0; i--)
    {
        if (flag & 0x01)
        {
            double data;
            file.read(reinterpret_cast<char*>(&data), sizeof(double));
            parameters_[i] = data;
        } else
        {
            parameters_[i] = nullopt;
        }
        flag = flag >> 1;
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

void DataFile::info(ostringstream& builder, const size_t index) const
{
    builder << PARAMETER_MAP[index] << ": ";
    if (parameters_[index].has_value()) builder << parameters_[index].value();
    else builder << "NULL";
}

void DataFile::info(ostringstream& builder) const
{
    for (size_t i = 0; i < PARAMETER_MAP.size(); i++)
    {
        info(builder, i);
    }
}

string DataFile::info(const size_t index) const
{
    ostringstream builder;
    info(builder, index);
    return builder.str();
}

string DataFile::info() const
{
    ostringstream builder;
    info(builder);
    return builder.str();
}

void DataFile::save()
{
    file_.seekp(1);
    uint8_t flag = 0;
    for (int i = 0; i < 7; i++)
    {
        if (parameters_[i].has_value())
        {
            file_.write(reinterpret_cast<char*>(&parameters_[i].value()), sizeof(double));
        } else
        {
            file_.write(nullptr, sizeof(double));
            flag = flag | 0x01;
        }
        flag = flag << 1;
    }
    file_.seekp(0);
    file_.write(reinterpret_cast<char*>(&flag), sizeof(uint8_t));
}
