#pragma once
#include <string_view>
#include <commsdsl/Frame.h>
namespace protodoc
{
class Backend
{
  public:
    virtual std::string buildChapter(int level, const std::string &title) const = 0;
    virtual std::string testFrame(const commsdsl::Frame &frame) const = 0;
};
} // namespace protodoc
