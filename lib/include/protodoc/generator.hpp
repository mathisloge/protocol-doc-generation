#pragma once
#include <filesystem>
#include <memory>
#include <vector>
#include <commsdsl/Protocol.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
using FilesList = std::vector<std::filesystem::path>;
struct GeneratorOpts
{
    bool trim;
    bool split;
    bool json_output;
    std::filesystem::path custom_json;
    std::filesystem::path lang_json;
    std::filesystem::path output_dir;
    FilesList files;
    struct
    {
        std::filesystem::path t_root_dir;
        std::filesystem::path t_platforms;
        std::filesystem::path t_namespaces;
        std::filesystem::path t_namespace;
    } templates;
};
class Generator
{
  private:
    static constexpr const char *kKeyPlatforms = "platforms";
    static constexpr const char *kKeyNamespace = "namespaces";

  public:
    Generator();
    bool generate(const GeneratorOpts &opts);

  private:
    bool parseSchemaFiles(const FilesList &files);
    bool write(const GeneratorOpts &opts);
    bool writePlatforms(nlohmann::ordered_json &json);
    bool writeNamespaces(nlohmann::ordered_json &json);

  private:
    commsdsl::Protocol protocol_;
};
} // namespace protodoc
