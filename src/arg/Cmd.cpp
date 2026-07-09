// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /src/arg/Cmd.cpp
// Command line handler.

#include <iostream>

#include <pac/arg/Cmd.hpp>
#include <pac/io/PacProject.hpp>
#include <pac/arg/CmdError.hpp>
#include <pac/core/Logger.hpp>
#include <pac/core/Message.hpp>
#include <pac/math/Calculate.hpp>

using namespace std;

int command(const int argc, char* argv[])
{
    CLI::App app("Parabolic Antenna Calculator");

    app.set_version_flag(
        "-v,--version",
        "Parabolic Antenna Calculator Version 0.1.0"
    );

    app.footer(HELP_FOOTER.data());

    bool debug_mode = false;
    app.add_flag("--debug", debug_mode, "Enable debug mode");
    string path;
    app.add_option("path", path, "Path of the project.")->required();

    auto* init = app.add_subcommand("init", "Initialize the project.");

    auto* para = app.add_subcommand("para", "About the parameter.");
    para->footer(PARA_HELP_FOOTER.data());
    optional<string> name;
    double value;
    auto* para_set = para->add_subcommand("set", "set the parameter");
    para_set->add_option("name", name, "Parameter name")->required();
    para_set->add_option("value", value, "Parameter value")->required();
    auto* para_value = para->add_subcommand("value", "set the multiple parameter value");
    array<optional<double>, 7> paras = addParaOptions(para_value);
    auto* para_delete = para->add_subcommand("delete", "Delete the parameter");
    para_delete->add_option("name", name, "Parameter name")->required();
    auto* para_show = para->add_subcommand("show", "Show the parameter list");
    para_show->add_option("name", name, "Parameter name");

    auto* run = app.add_subcommand("run", "Start the calculator.");
    run->add_option("--step", value, "Parameter step");

    CLI11_PARSE(app, argc, argv);

    if (debug_mode) logger.enableDebug();

    logger.debug("[arg/Cmd.cpp:command] The command handler was parsed");

    if (*init)
    {
        logger.debug("[arg/Cmd.cpp:command] Input the init command");
        Project::init(path);
        logger.debug("[arg/Cmd.cpp:command] The init command was finished");
        return EXIT_SUCCESS;
    }

    Project project = Project::open(path);
    logger.debug("[arg/Cmd.cpp:command] Project was built");

    if (*para)
    {
        logger.debug("[arg/Cmd.cpp:command] Input the para command");
        size_t matched_name;
        if (name.has_value())
        {
            logger.debug("[arg/Cmd.cpp:command] Has parameter name");
            auto unmatch_name = matchName(name.value());
            if (!unmatch_name.has_value())
            {
                logger.error(unmatch_name.error().getMessage() + name.value());
                return shutdown(std::move(project));
            }
            matched_name = unmatch_name.value();
            logger.debug("[arg/Cmd.cpp:command] Matched the parameter name");
        }
        DataFile& data_file = project.getDataFile();
        if (*para_set)
        {
            logger.debug("[arg/Cmd.cpp:command] Input the set command");
            auto unmatched_old_value = data_file.setParameter(matched_name, value);
            string old_value = unmatched_old_value.has_value() ? format(" from {:.3f}", unmatched_old_value.value()) : "";
            logger.info("[arg/Cmd.cpp:command] Set parameter " + name.value() + old_value + " to " + to_string(value));
            data_file.save();
            logger.debug("[arg/Cmd.cpp:command] Data file was saved");
        } else if (*para_value)
        {
            logger.debug("[arg/Cmd.cpp:command] Input the value command");
            for (size_t i = 0; i < 7; i++)
                if (paras[i].has_value())
                    data_file.setParameter(i, paras[i].value());
            data_file.save();
        }
        else if (*para_delete)
        {
            logger.debug("[arg/Cmd.cpp:command] Input the delete command");
            data_file.deleteParameter(matched_name);
            logger.info("[arg/Cmd.cpp:command] Delete parameter" + to_string(value));
            data_file.save();
            logger.debug("[arg/Cmd.cpp:command] Data file was saved");
        } else if (*para_show)
        {
            logger.debug("[arg/Cmd.cpp:command] Input the show command");
            if (name.has_value()) logger.info(data_file.info(matched_name));
            else logger.info(data_file.info());
        }
    } else if (*run)
    {
        logger.debug("[arg/Cmd.cpp:command] Input the run command");
        Calculator calculator(project.getDataFile().getParameterList());
        logger.debug("[arg/Cmd.cpp:command] The calculator entry was created");
        optional<AntennaEntryError> error;
        logger.debug(format("[arg/Cmd.cpp:command] Input step {}", value));
        error = calculator.step(value);
        if (error.has_value())
        {
            logger.error(format("[arg/Cmd.cpp:command] Calculate error message: {}", error.value().getMessage()));
            shutdown(std::move(project), -1);
        } else project.getDataFile().save();
    } else logger.debug("[arg/Cmd.cpp:command] The subcommand wasn't matched");
    return shutdown(std::move(project));
}

int shutdown(Project project)
{
    return shutdown(std::move(project), EXIT_SUCCESS);
}

int shutdown(Project project, const int code)
{
    logger.info("[arg/Cmd.cpp:shutdown] Close the project");
    project.close();
    return code;
}

array<optional<double>, 7> addParaOptions(CLI::App* app)
{
    array<optional<double>, 7> para;
    for (size_t i = 0; i < 7; i++)
    {
        string crossbar = "--";
        crossbar += PARAMETER_MAP[i];
        app->add_option(crossbar , para[i], PARAMETER_MAP[i]);
    }
    return para;
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
