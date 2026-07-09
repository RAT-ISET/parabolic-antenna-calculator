// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/io/DataFile.cpp
// Reader and writer for data file.

#include <pac/io/DataFile.hpp>
#include <pac/io/IoError.hpp>
#include <pac/math/Prefix.hpp>

void DataFile::initDataFile(ofstream& file)
{
    file.write(DATA_FILE_INITIALIZER.data(), DATA_FILE_SIZE);
}

DataFile::DataFile(fstream file)
{
    logger.debug("[io::DataFile::DataFile] Initialize the DataFile");
    data_file_ = std::move(file);

    if (data_file_.fail() || !data_file_.is_open())
    {
        logger.error("[io::DataFile::DataFile] Data file was cannot opened");
        analyzeFileError(data_file_);
        exit(-1);
    }

    logger.debug("[io::DataFile::DataFile] Data file was opened");

    data_file_.seekg(0);
    uint8_t flag;
    data_file_.read(reinterpret_cast<char*>(&flag), sizeof(uint8_t));

    logger.debug(format("[io/DataFile.cpp:DataFile] flag: {:b}", flag));

    for (int i = 0; i < 8; i++)
    {
        logger.debug(format("[io/DataFile.cpp:DataFile] The location {} status {}", i, flag & 0x01));
        if (flag & 0b10000000)
        {
            double data;
            data_file_.read(reinterpret_cast<char*>(&data), sizeof(double));
            logger.debug(format("[io/DataFile.cpp:DataFile] Read value {:.3f} from location {} ptr {}", data, i, static_cast<streamoff>(data_file_.tellg()) - sizeof(double)));
            parameters_[i] = data;
        } else
        {
            parameters_[i] = nullopt;
            data_file_.seekg(sizeof(double), ios::cur);
            logger.debug(format("[io/DataFile.cpp:DataFile] Read Empty from location {} ptr {}", i, static_cast<streamoff>(data_file_.tellg()) - sizeof(double)));
        }
        flag = flag << 1;
    }
}

optional<double> DataFile::setParameter(const size_t index, double value)
{
    const auto old_value = parameters_[index];
    parameters_[index] = value;
    return old_value;
}

optional<double> DataFile::deleteParameter(const size_t index)
{
    const auto value = parameters_[index];
    parameters_[index] = nullopt;
    return value;
}

optional<double> DataFile::getParameter(const size_t index) const
{
    return parameters_[index];
}

ParameterList& DataFile::getParameterList()
{
    return parameters_;
}

void DataFile::info(ostringstream& builder, const size_t index) const
{
    builder << PARAMETER_MAP[index] << ": ";
    if (parameters_[index].has_value()) builder << prefixFormat(parameters_[index].value()) << PARAMETER_UNIT[index];
    else builder << "Empty";
}

void DataFile::info(ostringstream& builder) const
{
    for (size_t i = 0; i < PARAMETER_MAP.size(); i++)
    {
        builder << endl;
        info(builder, i);
    }
}

string DataFile::info(const size_t index) const
{
    ostringstream builder;
    info(builder, index);
    return builder.str();
}

string DataFile::info() const
{
    ostringstream builder;
    info(builder);
    return builder.str();
}

void DataFile::save()
{
    data_file_.seekp(1);
    uint8_t flag = 0;
    for (int i = 0; i < 8; i++)
    {
        logger.debug(format("[io/DataFile.cpp:save] The location {} status {}", i, parameters_[i].has_value()));
        if (parameters_[i].has_value())
        {
            data_file_.write(reinterpret_cast<char*>(&parameters_[i].value()), sizeof(double));
            logger.debug(format("[io/DataFile.cpp:save] Write value {:.3f} to location {} ptr {}", parameters_[i].value(), i, static_cast<streamoff>(data_file_.tellp()) - sizeof(double)));
            flag = flag | 0x01;
        } else
        {
            data_file_.write(EMPTY_PARAMETER_SIZE.data(), sizeof(double));
            logger.debug(format("[io/DataFile.cpp:save] Write Empty to location {} ptr {}", i, static_cast<streamoff>(data_file_.tellp()) - sizeof(double)));
        }
        logger.debug(format("[io/DataFile.cpp:save] Write location {} status at {}", i, parameters_[i].has_value()));
        if (i != 7) flag = flag << 1;
        logger.debug(format("[io/DataFile.cpp:save] Move flag to {:b}", flag));
    }

    logger.debug(format("[io/DataFile.cpp:DataFile] flag: {:b}", flag));

    data_file_.seekp(0);
    data_file_.write(reinterpret_cast<char*>(&flag), sizeof(uint8_t));
}

void DataFile::close()
{
    data_file_.close();
}
