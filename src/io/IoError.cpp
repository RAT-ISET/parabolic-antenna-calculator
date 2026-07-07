// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/io/IoError.cpp
// Io error.

#include <pac/io/IoError.hpp>
#include <pac/io/PacProject.hpp>

void analyzeFileError(fstream& file)
{
    stringstream ss;
    ss << "[io/IoError.cpp/analyzeFileError]" << endl;
    ss << "is_open: " << file.is_open() << endl;
    ss << "good: " << file.good() << endl;
    ss << "fail: " << file.fail() << endl;
    ss << "bad: " << file.bad() << endl;
    ss << "eof: " << file.eof() << endl;
    logger.debug(ss.view());
};
