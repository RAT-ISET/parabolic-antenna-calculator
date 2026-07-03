// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/core/Logger.cpp
// Calculater log recorder.

#include <pac/core/Logger.hpp>
#include <iostream>
#include <sstream>
#include <pac/core/Definition.hpp>

void LogEntry::recordLogEntryBuilder(ostringstream& stream) const
{
    stream << "Input Parameter: ";
    for (int i = 0; i < input_.size(); i++) stream << PARAMETER_MAP[input_[i]] << " ";
    if (output_.has_value()) stream << "Output Parameter: " << output_.value() << endl;
    else stream << "No Output Parameter" << endl;
}

string LogEntry::recordLogEntry() const
{
    ostringstream result;
    recordLogEntryBuilder(result);
    return result.str();
}

Logger::Logger(LogFile& file)
: entries_(vector<LogEntry>())
, file_(file)
{}

void Logger::addEntry(LogEntry entry)
{
    entries_.push_back(std::move(entry));
}

void Logger::error(const string_view message) const
{
    file_.recordError(message);
    cerr << "[ERROR]" << message << endl;
}

void Logger::info(const string_view message) const
{
    file_.recordLog(message);
    cout << "[INFO]" << message << endl;
}

void Logger::recordEntries() const
{
    ostringstream result;
    for (LogEntry entry : entries_) entry.recordLogEntryBuilder(result);
    file_.recordLog(result.str());
}
