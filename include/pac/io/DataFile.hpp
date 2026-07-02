// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /include/pac/io/DataFile.hpp
// Header file of the reader and writer for data file.

#pragma once

#include <fstream>
#include <array>
#include <optional>
#include <pac/core/Definition.hpp>

using namespace std;

class DataFile
{
    fstream file_;
    ParameterList parameters_;
public:
    explicit DataFile(fstream file);
    optional<double> setParameter(size_t index, double value);
    optional<double> deleteParameter(size_t index);
    optional<double> getParameter(size_t index) const;
    ParameterList& getParameterList();
    string info(size_t index);
    string info();
    void save();
};
