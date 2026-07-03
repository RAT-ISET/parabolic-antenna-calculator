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

Project::Project(string path, DataFile data_file)
: path_(std::move(path))
, data_file_(std::move(data_file)) {}

Project Project::init(string path)
{
    filesystem::create_directories(path);
    return open(std::move(path));
}

Project Project::open(string path)
{
    fstream data_file_path(path + "/data.bin", fstream::out | fstream::in | fstream::binary);
    ofstream log_file_path(path + "/log.txt");
    DataFile data(std::move(data_file_path));
    LogFile log(std::move(log_file_path));
    return Project(std::move(path), std::move(data));
}

DataFile& Project::getDataFile()
{
    return data_file_;
}
