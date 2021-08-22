#include "message.hpp"
#include <commsdsl/Protocol.h>
#include "field.hpp"
#include "types.hpp"
namespace protodoc
{
void to_json(json_obj &j, const commsdsl::Message &message)
{
    j[kKeyFieldName] = message.name();
    if (!message.displayName().empty())
        j[kKeyFieldDisplayName] = message.displayName();
    if (!message.description().empty())
        j[kKeyFieldDescription] = message.description();
    auto test = json_obj::object();
    if (!j.contains(kKeyFields))
        j[kKeyFields] = json_obj::object();
    else
    {
        auto f = json_obj::object();
        for (const auto &field : j[kKeyFields])
            f.emplace_back(field);
        j[kKeyFields] = f;
    }

    for (const auto &f : message.fields())
    {
        to_json(test[f.name()], f);
    }
    j[kKeyFields] = std::move(test);
    if (commsdsl::Protocol::notYetDeprecated() != message.deprecatedSince())
        j[kKeyFieldDeprecatedSince] = message.deprecatedSince();
    j[kKeyFieldSinceVersion] = message.sinceVersion();
}
} // namespace protodoc
