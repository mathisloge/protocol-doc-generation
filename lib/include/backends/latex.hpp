#pragma once
#include "../backend.hpp"
namespace protodoc::backends
{
class Latex : public Backend
{
  public:
    std::string buildChapter(int level, const std::string &title) const override;
};
} // namespace protodoc::backends
