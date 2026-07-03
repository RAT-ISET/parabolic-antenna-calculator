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
    log_file_ << "[" << THREAD_ID << "][" << getFormatedTime() << "]" << message << endl;
}

void LogFile::recordLog(const string_view header, const string_view message)
{
    log_file_ << header;
    record(message);
}

void LogFile::close()
{
    log_file_.close();
    free(this);
}
