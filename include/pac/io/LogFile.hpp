// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /include/pac/io/LogFile.hpp
// Header file of the reader and writer for log file.

#pragma once

#include <fstream>

using namespace std;

class LogFile
{
    ofstream log_file_;
public:
    explicit LogFile(ofstream file);
    void recordLog(string_view message);
    void recordError(string_view message);
};
