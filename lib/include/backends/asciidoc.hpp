#pragma once
#include <memory>
#include "diagram.hpp"
#include "backend.hpp"
namespace protodoc
{
namespace backends
{
class Asciidoc : public Backend
{
  public:
    Asciidoc();
    std::string buildChapter(int level, const std::string &title) const override;
    std::string testFrame(const commsdsl::Frame &frame) const override;

  private:
    std::unique_ptr<Diagram> diagram_;
};
} // namespace backends
} // namespace protodoc
