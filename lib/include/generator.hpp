#pragma once
#include <filesystem>
#include <memory>
#include <vector>
#include <commsdsl/Protocol.h>

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
    bool writeFrames();
    bool writeMessages();

  private:
    commsdsl::Protocol protocol_;
};
} // namespace protodoc
