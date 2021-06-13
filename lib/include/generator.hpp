#pragma once
#include <filesystem>
#include <memory>
#include <vector>
#include <commsdsl/Protocol.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
class Generator
{
  private:
    using FilesList = std::vector<std::filesystem::path>;

  public:
    explicit Generator();
    bool generate(const FilesList &files);

  private:
    bool parseSchemaFiles(const FilesList &files);
    bool write();
    bool writePlatforms(nlohmann::json &json);
    bool writeFrames(nlohmann::json &json);
    bool writeMessages(nlohmann::json &json);

    void mergeCustomJson(nlohmann::json &custom, nlohmann::json &json);

  private:
    commsdsl::Protocol protocol_;
};
} // namespace protodoc
