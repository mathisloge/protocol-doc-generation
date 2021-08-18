#include "message.hpp"
#include <commsdsl/Protocol.h>
#include "field.hpp"
namespace protodoc
{
void to_json(json_obj &j, const commsdsl::Message &message)
{
    j["name"] = message.displayName().empty() ? message.name() : message.displayName();
    j["description"] = message.description();
    auto test = json_obj::object();
    if (!j.contains("fields"))
        j["fields"] = json_obj::object();
    else
    {
        auto f = json_obj::object();
        for (const auto &field : j["fields"])
            f.emplace_back(field);
        j["fields"] = f;
    }

    for (const auto &f : message.fields())
    {
        to_json(test[f.name()], f);
    }
    j["fields"] = std::move(test);
    if (commsdsl::Protocol::notYetDeprecated() != message.deprecatedSince())
        j["deprecatedSince"] = message.deprecatedSince();
    j["sinceVersion"] = message.sinceVersion();
}
} // namespace protodoc
