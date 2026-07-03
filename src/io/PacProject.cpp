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
, log_file_(std::move(log_file))
{
    logger.debug("[io/ParProject.cpp:Project] The project was loaded");
}

Project Project::init(string path)
{
    logger.debug("[io/ParProject.cpp:init] Initialize the project");
    filesystem::create_directories(path);
    logger.debug("[io/ParProject.cpp:init] Directories was created");
    ofstream data_file(path + "/data.bin", ios::binary);
    logger.debug("[io/ParProject.cpp:init] Data file was created");
    DataFile::initDataFile(data_file);
    logger.debug("[io/ParProject.cpp:init] Data file was initialized");
    data_file.close();
    return open(std::move(path));
}

Project Project::open(string path)
{
    logger.debug("[io/ParProject.cpp:open] Open the project");
    ofstream log_file_path(path + "/log.txt", ios::app);
    fstream data_file_path(path + "/data.bin", ios::out | ios::in | ios::binary);
    logger.debug("[io/ParProject.cpp:open] File was opened");
    LogFile log(std::move(log_file_path));
    logger.load(log);
    logger.info("[io/ParProject.cpp:open] LogFile was loaded");
    DataFile data(std::move(data_file_path));
    logger.info("[io/ParProject.cpp:open] DataFile was loaded");
    Project project(std::move(path), std::move(data), std::move(log));
    logger.load(project.getLogFile());
    return project;
}

DataFile& Project::getDataFile()
{
    return data_file_;
}

LogFile& Project::getLogFile()
{
    return log_file_;
}

void Project::close()
{
    logger.debug("[io/Project.cpp:close] Close the data file");
    data_file_.close();
    logger.debug("[io/Project.cpp:close] Close the log file");
    log_file_.close();
    free(this);
}
