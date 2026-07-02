// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculater
// ==============================================================
// Path /src/arg/Cmd.cpp
// Command line handler.

#include <iostream>

#include <CLI/CLI.hpp>
#include <pac/arg/Cmd.hpp>
#include <pac/io/PacProject.hpp>
#include <pac/arg/CmdError.hpp>
#include <pac/core/Logger.hpp>

using namespace std;

int command(const int argc, char* argv[])
{
    CLI::App app("Parabolic Antenna Calculater");

    app.set_version_flag(
        "-v,--version",
        "Parabolic Antenna Calculater Version 0.1.0"
    );

    app.footer(
        R"(Copyright (c) 2026 Team ISET
        License: MIT
        https://github.com/RAT-ISET/parabolic-antenna-calculater
    )");

    auto* init = app.add_subcommand("init", "Initialize the project.");
    string path;
    init->add_option("path", path, "Path of the project.")->required();

    auto* para = app.add_subcommand("para", "About the parameter.");
    optional<string> name;
    string value;
    auto* para_set = para->add_subcommand("set", "set the parameter");
    para_set->add_option("name", name, "Parameter name")->required();
    para_set->add_option("value", value, "Parameter value")->required();
    auto* para_delete = para->add_subcommand("delete", "Delete the parameter");
    para_delete->add_option("name", name, "Parameter name")->required();
    auto* para_show = para->add_subcommand("show", "Show the parameter list");
    para_show->add_option("name", name, "Parameter name");

    auto* run = app.add_subcommand("run", "Start the calculator.");
    run->add_option("--step", value, "Parameter step");

    CLI11_PARSE(app, argc, argv);

    if (*init)
    {
        Project::init(path);
    }

    Project project = Project::open("");

    if (*para)
    {
        size_t matched_name;
        if (name.has_value())
        {
            auto unmatch_name = matchName(name.value());
            if (!unmatch_name.has_value())
            {
                logger->error(unmatch_name.error().getMessage() + name.value());
                return EXIT_SUCCESS;
            }
            matched_name = unmatch_name.value();
        }
        DataFile& data_file = project.getDataFile();
        if (*para_set)
        {
            if (auto unmatch_value = matchValue(value); unmatch_value.has_value())
            {
                data_file.setParameter(matched_name, unmatch_value.value());
                logger->info("Add parameter" + value + " to " + name.value());
            } else
            {
                logger->error(unmatch_value.error().getMessage() + value);
            }
        } else if (*para_delete)
        {
            data_file.deleteParameter(matched_name);
            logger->info("Delete parameter" + value);
        } else if (*para_show)
        {
            if (name.has_value()) logger->info(data_file.info(matched_name));
            else logger->info(data_file.info());
        }
    }

    return EXIT_SUCCESS;
}

expected<size_t, CmdError> matchName(const string& name)
{
    if (const auto parameter = ranges::find(PARAMETER_MAP, name); parameter == PARAMETER_MAP.end())
    {
        return unexpected(CmdError(CmdErrorEnum::UnmatchParameter, name));
    } else
    {
        auto index = distance(PARAMETER_MAP.begin(), parameter);
        return index;
    }
}

expected<double, CmdError> matchValue(const string& value)
{
    try
    {
        double data = stod(value);
        return data;
    } catch (const invalid_argument&)
    {
        return unexpected(CmdError(CmdErrorEnum::InvalidArgument, value));
    } catch (const out_of_range&)
    {
        return unexpected(CmdError(CmdErrorEnum::OutOfRange, value));
    }
}
