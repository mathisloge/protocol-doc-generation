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
    static constexpr const char *kKeyPlatforms = "platforms";
    static constexpr const char *kKeyFrames = "frames";
    static constexpr const char *kKeyMessages = "messages";

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
