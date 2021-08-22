#include "protodoc/generator.hpp"
#include <fstream>
#include <sstream>
#include <commsdsl/EnumField.h>
#include <commsdsl/version.h>
#include <inja/environment.hpp>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include "inja_callbacks.hpp"
#include "json/json.hpp"

namespace protodoc
{

class Generator::Impl final
{
  public:
    Impl() = default;
    ~Impl() = default;
    commsdsl::Protocol protocol_;
};

Generator::Generator()
    : impl_{std::make_unique<Impl>()}
{}

bool Generator::generate(const GeneratorOpts &opts)
{
    return parseSchemaFiles(opts.files) && write(opts);
}

bool Generator::parseSchemaFiles(const FilesList &files)
{
    for (auto &f : files)
    {
        spdlog::info("Parsing {}", f.string());
        if (!impl_->protocol_.parse(f.string()))
        {
            return false;
        }
    }

    if (!impl_->protocol_.validate())
    {
        return false;
    }

    auto schema = impl_->protocol_.schema();

    if (commsdsl::versionMajor() < schema.dslVersion())
    {
        spdlog::error("Required DSL version is too big ({}), upgrade your code generator.", schema.dslVersion());
        return false;
    }

    return true;
}

bool Generator::write(const GeneratorOpts &opts)
{
    //! \todo base on program options
    inja::Environment env{opts.templates.t_root_dir.string() + '/', opts.output_dir.string() + '/'};

    //! \todo make these customizable via program options
    env.set_expression("{^", "^}"); // Expressions
    env.set_comment("{#", "#}");    // Comments
    env.set_statement("{%", "%}");  // Statements {% %} for many things, see below
    env.set_line_statement("##");   // Line statements ## (just an opener)

    env.set_trim_blocks(opts.trim);    // remove new line after a command
    env.set_lstrip_blocks(opts.split); // remove whitespaces and tabs from the beginning to the start of a block

    env.add_callback("latexText", 1, callbacks::latexText);
    env.add_callback("sortEnum", 2, callbacks::sortEnum);

    json_obj json;
    if (!opts.custom_json.empty())
    {
        std::ifstream ifs{opts.custom_json};
        auto custom_json = json_obj::parse(ifs);
        json.update(custom_json);
    }

    const auto written_dsl = writePlatforms(json) && writeNamespaces(json);

    std::ifstream ifs{opts.lang_json};
    const auto lang_json = json_obj::parse(ifs);
    { // update all keys with the lang specs
        json.merge_patch(lang_json);
    }

    if (opts.json_output)
    {
        spdlog::info("root: {}", opts.root.string());
        std::ofstream json_output_file{opts.output_dir / "protodoc_internal.json"};
        json_output_file << std::setw(4) << json << std::endl;
    }
    // try
    // {
    // std::cout << env.render_file("platforms.tex", json) << std::endl;
    if (json.find("platforms") != json.end())
    {
        spdlog::info("Writing platforms...");
        const std::string platforms_ext{opts.templates.t_platforms.extension().string()};
        env.write(opts.templates.t_platforms.string(), json, "platforms" + platforms_ext);
    }
    // env.write("frames.adoc", json, "frames.adoc");
    spdlog::info("Writing namespaces...");
    const std::string namespaces_ext{opts.templates.t_namespaces.extension().string()};
    env.write(opts.templates.t_namespaces.string(), json, "namespaces" + namespaces_ext);

    const std::string namespace_ext{opts.templates.t_namespace.extension().string()};
    for (auto &[key, val] : json[kKeyNamespace].items())
    {
        spdlog::info("Writing namespace {}...", key);
        inja::json ns_json{{kKeyNamespace, val}};
        ns_json.merge_patch(lang_json);
        std::ofstream ns_json_file(opts.output_dir / (key + ".json"));
        ns_json_file << std::setw(4) << ns_json << std::endl;
        env.write(opts.templates.t_namespace.string(), ns_json, key + namespace_ext);
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
        json[kKeyPlatforms][kKeyPlatforms] = json_obj::object();
    json[kKeyPlatforms][kKeyPlatforms] = impl_->protocol_.platforms();
    return true;
}

bool Generator::writeNamespaces(json_obj &json)
{
    for (const auto &ns : impl_->protocol_.namespaces())
    {
        const std::string ns_name = ns.name().empty() ? "global" : ns.name();
        if (!json[kKeyNamespace].contains(ns_name))
            json[kKeyNamespace][ns_name] = json_obj::object();
        auto &ns_json = json[kKeyNamespace][ns_name];
        to_json(ns_json, ns);
    }
    return true;
}

Generator::~Generator()
{}

} // namespace protodoc
