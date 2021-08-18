#include "inja_callbacks.hpp"

namespace protodoc::callbacks
{
std::string latexText(inja::Arguments &args)
{
    auto replace_all = [](std::string &inout, std::string_view what, std::string_view with) -> std::size_t {
        std::size_t count{};
        for (std::string::size_type pos{}; inout.npos != (pos = inout.find(what.data(), pos, what.length()));
             pos += with.length(), ++count)
        {
            inout.replace(pos, what.length(), with.data(), with.length());
        }
        return count;
    };
    auto text = args.at(0)->get<std::string>();
    replace_all(text, "_", "\\_");
    return text;
}
} // namespace protodoc
