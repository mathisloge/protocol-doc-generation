#include "generator.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <commsdsl/EnumField.h>
#include <commsdsl/version.h>
#include <inja/environment.hpp>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include "json/json.hpp"
namespace protodoc
{

Generator::Generator()
{}

bool Generator::generate(const FilesList &files)
{
    return parseSchemaFiles(files) && write();
}

bool Generator::parseSchemaFiles(const FilesList &files)
{
    for (auto &f : files)
    {
        spdlog::info("Parsing {}", f.string());
        if (!protocol_.parse(f.string()))
        {
            return false;
        }
    }

    if (!protocol_.validate())
    {
        return false;
    }

    auto schema = protocol_.schema();

    if (commsdsl::versionMajor() < schema.dslVersion())
    {
        spdlog::error("Required DSL version is too big ({}), upgrade your code generator.", schema.dslVersion());
        return false;
    }

    return true;
}

bool Generator::write()
{
    //! \todo base on program options
    inja::Environment env{"D:/dev/protocol-doc-generation/templates/asciidoc/", "D:/dev/commsdsl_text/asciidoc/gen/"};
    const auto lang_file = "D:/dev/protocol-doc-generation/templates/lang_en.json";
    const auto custom_file = "D:/dev/protocol-doc-generation/templates/custom.json";

    //! \todo make these customizable via program options
    env.set_expression("{^", "^}"); // Expressions
    env.set_comment("{#", "#}");    // Comments
    env.set_statement("{%", "%}");  // Statements {% %} for many things, see below
    env.set_line_statement("##");   // Line statements ## (just an opener)

    env.set_trim_blocks(true);   // remove new line after a command
    env.set_lstrip_blocks(true); // remove whitespaces and tabs from the beginning to the start of a block

    env.add_callback("latexText", 1, [](inja::Arguments &args) {
        auto replace_all = [](std::string &inout, std::string_view what, std::string_view with) -> std::size_t {
            std::size_t count{};
            for (std::string::size_type pos{}; inout.npos != (pos = inout.find(what.data(), pos, what.length()));
                 pos += with.length(), ++count)
            {
                inout.replace(pos, what.length(), with.data(), with.length());
            }
            return count;
        };
        auto text = args.at(0)->get<std::string>();
        replace_all(text, "_", "\\_");
        return text;
    });

    nlohmann::json json;
    {
        std::ifstream ifs{custom_file};
        auto custom_json = nlohmann::json::parse(ifs);
        json.update(custom_json);
    }

    const auto written_dsl = writePlatforms(json) && writeFrames(json) && writeMessages(json);

    { // update all keys with the lang specs
        std::ifstream ifs{lang_file};
        const auto lang_json = nlohmann::json::parse(ifs);
        json.merge_patch(lang_json);
    }
    std::ofstream MyFile("test.json");
    MyFile << std::setw(4) << json << std::endl;
    // try
    // {
    // std::cout << env.render_file("platforms.tex", json) << std::endl;
    env.write("platforms.adoc", json, "platforms.adoc");
    env.write("frames.adoc", json, "frames.adoc");
    env.write("messages.adoc", json, "messages.adoc");
    // }
    // catch (const std::exception &ex)
    // {
    //     std::cout << ex.what() << std::endl;
    // }

    return written_dsl;
}
bool Generator::writePlatforms(nlohmann::json &json)
{
    if (!json[kKeyPlatforms].contains(kKeyPlatforms))
        json[kKeyPlatforms][kKeyPlatforms] = nlohmann::json{};

    to_json(json[kKeyPlatforms][kKeyPlatforms], protocol_.platforms());

    return true;
}

bool Generator::writeFrames(nlohmann::json &json)
{
    if (!json[kKeyFrames].contains(kKeyFrames))
        json[kKeyFrames][kKeyFrames] = nlohmann::json{};
    for (const auto &ns : protocol_.namespaces())
    {
        for (const auto &frame : ns.frames())
        {
            to_json(json[kKeyFrames][kKeyFrames][frame.name()], frame);
        }
    }

    return true;
}

bool Generator::writeMessages(nlohmann::json &json)
{
    if (!json[kKeyMessages].contains(kKeyMessages))
        json[kKeyMessages][kKeyMessages] = nlohmann::json{};

    for (const auto &m : protocol_.allMessages())
    {
        to_json(json[kKeyMessages][kKeyMessages][m.name()], m);
    }
    return true;
}

} // namespace protodoc
