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

    const auto written_dsl = writePlatforms(json) && writeNamespaces(json);

    std::ifstream ifs{lang_file};
    const auto lang_json = json_obj::parse(ifs);
    { // update all keys with the lang specs
        json.merge_patch(lang_json);
    }
    std::ofstream MyFile("test.json");
    MyFile << std::setw(4) << json << std::endl;
    // try
    // {
    // std::cout << env.render_file("platforms.tex", json) << std::endl;
    env.write("platforms.adoc", json, "platforms.adoc");
    // env.write("frames.adoc", json, "frames.adoc");
    env.write("namespaces.adoc", json, "namespaces.adoc");

    for (auto &[key, val] : json[kKeyNamespace].items())
    {
        inja::json ns_json{{kKeyNamespace, val}};
        ns_json.merge_patch(lang_json);
        std::ofstream ns_json_file(key + ".json");
        ns_json_file << std::setw(4) << ns_json << std::endl;
        env.write("namespace.adoc", ns_json, key + ".adoc");
    }

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

bool Generator::writeNamespaces(json_obj &json)
{
    for (const auto &ns : protocol_.namespaces())
    {
        const std::string ns_name = ns.name().empty() ? "global" : ns.name();
        auto &ns_json = json[kKeyNamespace][ns_name];
        to_json(ns_json, ns);
    }
    return true;
}

} // namespace protodoc
