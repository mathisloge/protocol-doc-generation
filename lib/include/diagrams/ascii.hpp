#pragma once
#include "../diagram.hpp"
namespace protodoc::diagrams
{
class Ascii : public Diagram
{
  public:
    std::string getFrameLayout(const commsdsl::Frame &frame) const override;
};
} // namespace protodoc::diagrams
