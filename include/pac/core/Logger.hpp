// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /include/pac/core/Logger.hpp
// Header file of the calculater log recorder.

#pragma once

#include <vector>
#include <optional>
#include <string>

using namespace std;

struct LogEntry
{
    vector<size_t> input_;
    optional<vector<size_t>> output_;
    string recordLogEntry();
};

class Logger
{
    vector<LogEntry> entries_;
public:
    Logger() = default;
    void addEntry(LogEntry entry);
    string recordLog();
};
