// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/io/PacProject.hpp
// Header file of the project handle.

#pragma once

#include <pac/io/DataFile.hpp>

using namespace std;

class Project
{
    string path_;
    DataFile data_file_;
    LogFile log_file_;
    explicit Project(string path, DataFile data_file, LogFile log_file);
public:
    static Project init(string path);
    static Project open(string path);
    DataFile& getDataFile();
    LogFile& getLogFile();
    void close();
};
