#pragma once
#include <filesystem>
#include <memory>
#include <vector>
#include <commsdsl/Protocol.h>

namespace protodoc
{
class Backend;
class Generator
{
  private:
    using FilesList = std::vector<std::filesystem::path>;

  public:
    explicit Generator(std::unique_ptr<Backend> &&backend);
    bool generate(const FilesList &files);

  private:
    bool parseSchemaFiles(const FilesList &files);
    bool write();
    bool writeFrames();
    bool writeMessages();

  private:
    std::unique_ptr<Backend> backend_;
    commsdsl::Protocol protocol_;
};
} // namespace protodoc
