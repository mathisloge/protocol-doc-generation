#include "diagrams/ascii.hpp"
#include <fmt/format.h>
namespace protodoc::diagrams
{
std::string Ascii::getFrameLayout(const commsdsl::Frame &frame) const
{
    return fmt::format("┌{0:─^{1}}┐\n"
                       "│{2: ^{1}}│\n"
                       "├{0:┄^{1}}┤\n"
                       "│{3: ^{1}}│\n"
                       "└{0:─^{1}}┘\n",
                       "",
                       20,
                       "sync",
                       "2 byte");
}
} // namespace protodoc::diagrams
