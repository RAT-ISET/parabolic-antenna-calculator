// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/io/IoError.cpp
// Io error.

#include <pac/io/PacProject.hpp>

void analyzeFileError(fstream& file)
{
    stringstream ss;
    ss << "[io/IoError.cpp/analyzeFileError]";
    ss << " is_open: " << file.is_open();
    ss << " good: " << file.good();
    ss << " fail: " << file.fail();
    ss << " bad: " << file.bad();
    ss << " eof: " << file.eof();
    logger.debug(ss.view());
};
