// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /src/io/PacProject.cpp
// Project handle.

#include <filesystem>
#include <pac/io/PacProject.hpp>

using namespace std;

Project::Project(string path, DataFile data_file)
: path_(path)
, data_file_(std::move(data_file)) {}

Project Project::init(string path)
{
    filesystem::create_directories(path);
    return open(std::move(path));
}

Project Project::open(string path)
{
    fstream data_file_path(path + "/data.bin", fstream::out | fstream::in | fstream::binary);
    DataFile data(std::move(data_file_path));
    return Project(std::move(path), std::move(data));
}

DataFile& Project::getDataFile()
{
    return data_file_;
}
