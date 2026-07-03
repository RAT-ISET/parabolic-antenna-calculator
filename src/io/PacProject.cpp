// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/io/PacProject.cpp
// Project handle.

#include <pac/io/PacProject.hpp>
#include <filesystem>
#include <utility>
#include <pac/io/LogFile.hpp>

using namespace std;

Project::Project(string path, DataFile data_file, LogFile log_file)
: path_(std::move(path))
, data_file_(std::move(data_file))
, log_file_(std::move(log_file)) {}

Project Project::init(string path)
{
    logger.debug("[io/ParProject.cpp:init] Initialize the project");
    filesystem::create_directories(path);
    logger.debug("[io/ParProject.cpp:init] Directories was created");
    return open(std::move(path));
}

Project Project::open(string path)
{
    logger.debug("[io/ParProject.cpp:open] Open the project");
    fstream data_file_path(path + "/data.bin", fstream::out | fstream::in | fstream::binary);
    ofstream log_file_path(path + "/log.txt");
    logger.debug("[io/ParProject.cpp:open] File was opened");
    DataFile data(std::move(data_file_path));
    LogFile log(std::move(log_file_path));
    logger.load(log);
    logger.debug("[io/ParProject.cpp:open] LogFile was loaded");
    return Project(std::move(path), std::move(data), std::move(log));
}

DataFile& Project::getDataFile()
{
    return data_file_;
}

LogFile& Project::getLogFile()
{
    return log_file_;
}
