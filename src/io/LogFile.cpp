// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/io/LogFile.cpp
// Reader and writer for log file.

#include <pac/io/LogFile.hpp>
#include <pac/core/Definition.hpp>

LogFile::LogFile(ofstream file)
{
    log_file_ = std::move(file);
}

void LogFile::record(const string_view message)
{
    log_file_ << "[" << THREAD_ID << "][" << getFormatedTime() << "] " << message;
}

void LogFile::recordLog(const string_view message)
{
    log_file_ << "[INFO]";
    record(message);
}

void LogFile::recordError(string_view message)
{
    log_file_ << "[ERROR]";
    record(message);
}
