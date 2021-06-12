#include "backends/asciidoc.hpp"
#include <fmt/format.h>
#include "diagrams/ascii.hpp"
namespace protodoc::backends
{
Asciidoc::Asciidoc()
    : diagram_{std::make_unique<diagrams::Ascii>()}
{}
std::string Asciidoc::buildChapter(int level, const std::string &title) const
{
    return fmt::format("{0:=^{1}} {2}\n", "", level, title);
}

std::string Asciidoc::testFrame(const commsdsl::Frame &frame) const
{
    return diagram_->getFrameLayout(frame);
}
} // namespace protodoc::backends
