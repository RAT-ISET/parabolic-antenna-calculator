// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /include/pac/io/LogFile.hpp
// Header file of the reader and writer for log file.

#pragma once

#include <fstream>
#include <chrono>

using namespace std;

inline string getFormatedTime()
{
    using namespace std::chrono;
    const auto now = system_clock::now();
    return format("{:%Y-%m-%dT%H:%M:%S}",
        floor<seconds>(now),
        duration_cast<milliseconds>(now.time_since_epoch()).count() % 1000
    );
}

class LogFile
{
    ofstream log_file_;
    void record(string_view message);
public:
    explicit LogFile(ofstream file);
    void recordLog(string_view message);
    void recordError(string_view message);
};
