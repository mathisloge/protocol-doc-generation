#include "inja_callbacks.hpp"
#include <cassert>
#include <iostream>
#include <map>
#define assertm(exp, msg) assert(((void)msg, exp))

namespace protodoc::callbacks
{
inja::json latexText(inja::Arguments &args)
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

inja::json sortEnum(inja::Arguments &args)
{
    assertm(args.size() == 2, "Expected two args");
    assertm(args[1]->is_string(), "expected second argument to be a string");

    const inja::json &obj_list = *args[0];
    const std::string sort_key = args[1]->get<std::string>();

    std::map<int, std::string> idx_list;
    for (auto &[key, val] : obj_list.items())
        idx_list.emplace(val[sort_key].get<int>(), key);

    inja::json ret_list{inja::json::array()};
    for (const auto &v : idx_list)
        ret_list.emplace_back(v.second);

    return ret_list;
}
} // namespace protodoc::callbacks
