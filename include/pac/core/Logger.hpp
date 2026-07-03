// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/core/Logger.hpp
// Header file of the calculator log recorder.

#pragma once

#include <vector>
#include <optional>
#include <string>
#include <pac/io/LogFile.hpp>

using namespace std;

struct LogEntry
{
    vector<size_t> input_;
    optional<size_t> output_;
    void recordLogEntryBuilder(ostringstream& stream) const;
    [[nodiscard]] string recordLogEntry() const;
};

class Logger
{
    vector<LogEntry> entries_;
    LogFile* file_ = nullptr;
    bool loaded_ = false;
    bool debug_{};
public:
    explicit Logger();
    void addEntry(LogEntry entry);
    void error(string_view message) const;
    void info(string_view message) const;
    void debug(string_view message) const;
    void recordEntries() const;
    void load(LogFile& file);
    void enableDebug();
};
