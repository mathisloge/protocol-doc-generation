#include "generator.hpp"
#include <fstream>
#include <sstream>
#include <commsdsl/EnumField.h>
#include <commsdsl/version.h>
#include <inja/environment.hpp>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include "inja_callbacks.hpp"
#include "json/def.hpp"
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

    env.add_callback("latexText", 1, callbacks::latexText);
    env.add_callback("sortEnum", 2, callbacks::sortEnum);



    json_obj json;
    {
        std::ifstream ifs{custom_file};
        auto custom_json = json_obj::parse(ifs);
        json.update(custom_json);
    }

    const auto written_dsl = writePlatforms(json) && writeFrames(json) && writeMessages(json);

    { // update all keys with the lang specs
        std::ifstream ifs{lang_file};
        const auto lang_json = json_obj::parse(ifs);
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
bool Generator::writePlatforms(json_obj &json)
{
    if (!json[kKeyPlatforms].contains(kKeyPlatforms))
        json[kKeyPlatforms][kKeyPlatforms] = json_obj{};

    to_json(json[kKeyPlatforms][kKeyPlatforms], protocol_.platforms());

    return true;
}

bool Generator::writeFrames(json_obj &json)
{
    if (!json[kKeyFrames].contains(kKeyFrames))
        json[kKeyFrames][kKeyFrames] = json_obj{};
    for (const auto &ns : protocol_.namespaces())
    {
        for (const auto &frame : ns.frames())
        {
            to_json(json[kKeyFrames][kKeyFrames][frame.name()], frame);
        }
    }

    return true;
}

bool Generator::writeMessages(json_obj &json)
{
    if (!json[kKeyMessages].contains(kKeyMessages))
        json[kKeyMessages][kKeyMessages] = json_obj{};
    else
        json[kKeyMessages][kKeyMessages] = json_obj{json[kKeyMessages][kKeyMessages]};

    for (const auto &m : protocol_.allMessages())
    {
        to_json(json[kKeyMessages][kKeyMessages][m.name()], m);
    }
    return true;
}

} // namespace protodoc
