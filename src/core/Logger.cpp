// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/core/Logger.cpp
// Calculator log recorder.

#include <pac/core/Logger.hpp>
#include <iostream>
#include <sstream>
#include <pac/core/Definition.hpp>

void LogEntry::recordLogEntryBuilder(ostringstream& stream) const
{
    stream << "Input Parameter: ";
    for (const size_t i : input_) stream << PARAMETER_MAP[i] << " ";
    if (output_.has_value()) stream << "Output Parameter: " << output_.value() << endl;
    else stream << "No Output Parameter" << endl;
}

string LogEntry::recordLogEntry() const
{
    ostringstream result;
    recordLogEntryBuilder(result);
    return result.str();
}

Logger::Logger()
: entries_(vector<LogEntry>())
{}

void Logger::addEntry(LogEntry entry)
{
    entries_.push_back(std::move(entry));
}

void Logger::error(const string_view message) const
{
    if (loaded_) file_->recordLog("[ERROR]", message);
    cerr << "[ERROR]" << message << endl;
}

void Logger::info(const string_view message) const
{
    if (loaded_) file_->recordLog("[INFO]", message);
    cout << "[INFO]" << message << endl;
}

void Logger::debug(const string_view message) const
{
    if (!debug_) return;
    if (loaded_) file_->recordLog("[DEBUG]", message);
    cout << "[DEBUG]" << message << endl;
}

void Logger::recordEntries() const
{
    ostringstream result;
    for (const LogEntry& entry : entries_) entry.recordLogEntryBuilder(result);
    if (loaded_) file_->recordLog("[ACTION]", result.str());
}

void Logger::load(LogFile& file)
{
    file_ = &file;
    loaded_ = true;
}

void Logger::enableDebug()
{
    debug_ = true;
}
