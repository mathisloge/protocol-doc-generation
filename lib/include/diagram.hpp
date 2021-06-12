#pragma once
#include <string>
#include <commsdsl/Frame.h>
namespace protodoc
{
class Diagram
{
  public:
    virtual std::string getFrameLayout(const commsdsl::Frame &frame) const = 0;
};
} // namespace protodoc
