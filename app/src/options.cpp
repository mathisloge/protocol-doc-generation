#include "options.hpp"
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include "version.hpp"

namespace fs = std::filesystem;
using nlohmann::json;

static constexpr const char *kKeySettings = "settings";
static void printName();
void prepareOptions(cxxopts::Options &opts)
{
    // clang-format off
    opts.add_options()
        ("s,settings", "The project settings file", cxxopts::value<std::string>())
        ("h,help", "Print usage")
        ("v,version", "Print version")
        ;
    // clang-format on
}

static void checkForRequiredOpts(const cxxopts::ParseResult &res);
void parseOpts(const cxxopts::ParseResult &res, protodoc::GeneratorOpts &opts)
{
    checkForRequiredOpts(res);
    const fs::path settings_file{res[kKeySettings].as<std::string>()};
    if (!fs::exists(settings_file))
        throw std::runtime_error("settings file does not exists");
    else if (!fs::is_regular_file(settings_file))
        throw std::runtime_error("settings file is not a regular file");

    std::ifstream ifs{settings_file};
    const auto settings = json::parse(ifs);
    const auto templates = settings.at("templates");
    const auto lang = settings.at("lang");
    const auto output = settings.at("output");
    const auto custom = settings.find("custom");
    const auto trim = settings.find("trim");
    const auto split = settings.find("split");
    const auto jsonOutput = settings.find("jsonOutput");

    const fs::path settings_root = [&]() {
        const auto root_dir = settings.find("root");
        if (root_dir != settings.end())
            return fs::path{root_dir->get<std::string>()};
        return settings_file.parent_path();
    }();
    opts.root = settings_root;
    if (!fs::exists(opts.root))
    {
        if (!fs::create_directories(opts.root))
            throw std::runtime_error("settings: could not create root directory. Please create it first!");
    }
    else if (!fs::is_directory(opts.root))
        throw std::runtime_error(fmt::format("settings: root is not a directory: [{}]", opts.root.string()));

    { //! templates
        if (!templates.is_object())
            throw std::runtime_error("settings: templates is not a object");
        opts.templates.t_root_dir = settings_root;
        if (auto it = templates.find("root"); it != templates.end())
            opts.templates.t_root_dir = fs::path(it->get<std::string>());
        if (opts.templates.t_root_dir.is_relative())
            opts.templates.t_root_dir = settings_root / opts.templates.t_root_dir;
        spdlog::info("ROOT: {}", opts.templates.t_root_dir.string());
        if (!fs::is_directory(opts.templates.t_root_dir))
            throw std::runtime_error("settings: templates.root is not a directory");

        opts.templates.t_platforms = fs::path{templates.at("platforms").get<std::string>()};
        opts.templates.t_namespaces = fs::path{templates.at("namespaces").get<std::string>()};
        opts.templates.t_namespace = fs::path{templates.at("namespace").get<std::string>()};
        if (!fs::exists(opts.templates.t_root_dir / opts.templates.t_platforms) ||
            !fs::is_regular_file(opts.templates.t_root_dir / opts.templates.t_platforms))
            throw std::runtime_error("settings: templates.platforms does not exists or is not a file");
        if (!fs::exists(opts.templates.t_root_dir / opts.templates.t_namespaces) ||
            !fs::is_regular_file(opts.templates.t_root_dir / opts.templates.t_namespaces))
            throw std::runtime_error("settings: templates.namespaces does not exists or is not a file");
        if (!fs::exists(opts.templates.t_root_dir / opts.templates.t_namespace) ||
            !fs::is_regular_file(opts.templates.t_root_dir / opts.templates.t_namespace))
            throw std::runtime_error("settings: templates.namespace does not exists or is not a file");
    }
    { //! settings.output
        opts.output_dir = fs::path{output.get<std::string>()};
        if (opts.output_dir.is_relative())
            opts.output_dir = settings_root / opts.output_dir;
        if (!fs::exists(opts.output_dir))
        {
            if (!fs::create_directories(opts.output_dir))
                throw std::runtime_error("settings: could not create output directory. Please create it first!");
        }
        else if (!fs::is_directory(opts.output_dir))
            throw std::runtime_error("settings: output is not a directory");
    }
    { //! settings.lang
        opts.lang_json = fs::path{lang.get<std::string>()};
        if (opts.lang_json.is_relative())
            opts.lang_json = settings_root / opts.lang_json;
        if (!fs::exists(opts.lang_json) || !fs::is_regular_file(opts.lang_json))
            throw std::runtime_error("settings: lang does not exists or is not a file");
    }
    { //! settings.custom
        if (custom != settings.end())
        {
            opts.custom_json = fs::path{custom->get<std::string>()};
            if (opts.custom_json.is_relative())
                opts.custom_json = settings_root / opts.custom_json;
            if (!fs::exists(opts.custom_json) || !fs::is_regular_file(opts.custom_json))
                throw std::runtime_error("settings: custom does not exists or is not a file");
        }
    }
    { //! bool options
        opts.trim = (trim != settings.end()) ? trim->get<bool>() : false;
        opts.split = (split != settings.end()) ? split->get<bool>() : false;
        opts.json_output = (jsonOutput != settings.end()) ? jsonOutput->get<bool>() : false;
    }

    { //! create file list
        const auto files = settings.find("files");
        const auto inputDir = settings.find("inputDir");
        const auto responseFile = settings.find("responseFile");

        const bool files_present = (files != settings.end());
        const bool inputDir_present = (inputDir != settings.end());
        const bool responseFile_present = (responseFile != settings.end());

        if ((files_present + inputDir_present + responseFile_present) != 1)
            throw std::runtime_error("settings: it can only one of files, inputDir or responseFile be present");

        if (files_present)
        {
            if (!files->is_array())
                throw std::runtime_error("settings: files needs to be an array of schema xml files");
            for (auto it = files->begin(); it != files->end(); ++it)
            {
                fs::path input_file{it->get<std::string>()};
                if (input_file.is_relative())
                    input_file = settings_root / input_file;
                if (!fs::exists(input_file) || !fs::is_regular_file(input_file))
                    std::runtime_error("input file: \"" + input_file.string() +
                                       "\" does not exists or is not a schema file");
                opts.files.emplace_back(std::move(input_file));
            }
        }
        else if (inputDir_present)
        {
            fs::path input_dir{inputDir->get<std::string>()};
            if (input_dir.is_relative())
                input_dir = settings_root / input_dir;
            if (!fs::exists(input_dir))
                std::runtime_error("input dir: \"" + input_dir.string() + "\" does not exists");

            for (const auto &file : fs::recursive_directory_iterator(input_dir))
            {
                const fs::path &file_path{file.path()};
                if (file.is_regular_file() && file_path.has_extension() && file_path.extension() == ".xml")
                    opts.files.emplace_back(file_path);
            }
        }
        else if (responseFile_present)
        {
            fs::path file_path{responseFile->at("file").get<std::string>()};
            if (file_path.is_relative())
                file_path = settings_root / file_path;
            const fs::path path = fs::path{responseFile->at("path").get<std::string>()};
            std::ifstream file{file_path};
            for (std::string line; std::getline(file, line);)
            {
                const fs::path input_file{path / line};

                opts.files.emplace_back(std::move(input_file));
            }
        }
    }
}

void checkForRequiredOpts(const cxxopts::ParseResult &res)
{
    if (res.count(kKeySettings) == 0)
        throw std::runtime_error("settings not found");
}

void printVersion()
{
    printName();
    std::cout << "==============================================" << std::endl;
    std::cout << "version: " << protodoc::kVersion << std::endl;
    std::cout << "sha1: " << protodoc::kGitRef << std::endl;
    std::cout << "spec: " << protodoc::kGitRefSpec << std::endl;
    std::cout << "==============================================" << std::endl;
}

void printName()
{
    std::cout << R"(                                _             
                  _            | |            
 ____   ____ ___ | |_  ___   _ | | ___   ____ 
|  _ \ / ___) _ \|  _)/ _ \ / || |/ _ \ / ___)
| | | | |  | |_| | |_| |_| ( (_| | |_| ( (___ 
| ||_/|_|   \___/ \___)___/ \____|\___/ \____)
|_|                                           )"
              << std::endl;
}
