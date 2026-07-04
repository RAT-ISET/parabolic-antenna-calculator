// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/io/DataFile.hpp
// Header file of the reader and writer for data file.

#pragma once

#include <iostream>
#include <array>
#include <optional>
#include <pac/core/Definition.hpp>

using namespace std;

constexpr size_t DATA_FILE_SIZE = sizeof(uint8_t) + sizeof(double) * 8;
constexpr array<char, DATA_FILE_SIZE> DATA_FILE_INITIALIZER{};
constexpr array<char, sizeof(double)> EMPTY_PARAMETER_SIZE{};

class DataFile
{
    fstream data_file_;
    ParameterList parameters_;
public:
    static void initDataFile(ofstream& file);
    explicit DataFile(fstream file);
    optional<double> setParameter(size_t index, double value);
    optional<double> deleteParameter(size_t index);
    optional<double> getParameter(size_t index) const;
    ParameterList& getParameterList();
    void info(ostringstream& builder, size_t index) const;
    void info(ostringstream& builder) const;
    string info(size_t index) const;
    string info() const;
    void save();
    void close();
};
