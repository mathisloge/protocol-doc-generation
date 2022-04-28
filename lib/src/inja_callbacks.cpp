#include "inja_callbacks.hpp"
#include <cassert>
#include <iostream>
#include <map>
#include "json/def.hpp"
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

static inja::json InOrder(const inja::json &fields, const char *sort_key)
{
    std::map<int, std::string> idx_list;
    for (auto &[key, val] : fields.items())
        idx_list.emplace(val[sort_key].get<int>(), key);

    inja::json ret_list = inja::json::array();
    std::transform(idx_list.begin(), idx_list.end(), std::back_inserter(ret_list), [](auto &kv) { return kv.second; });

    return ret_list;
}

inja::json sortEnum(inja::Arguments &args)
{
    assertm(args.size() == 2, "Expected two args");
    assertm(args[1]->is_string(), "expected second argument to be a string");

    const inja::json &obj_list = *args[0];
    const std::string sort_key = args[1]->get<std::string>();

    return InOrder(obj_list, sort_key.c_str());
}

inja::json inOrder(inja::Arguments &args)
{
    const inja::json &fields = *args[0];
    assertm(args.size() == 1, "Expected one arg");
    return InOrder(fields, kKeyOrderIndex);
}

} // namespace protodoc::callbacks
