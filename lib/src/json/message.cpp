#include "message.hpp"
#include <commsdsl/Protocol.h>
#include "field.hpp"
namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::Message &message)
{
    j["name"] = message.displayName().empty() ? message.name() : message.displayName();
    j["description"] = message.description();
    if (!j.contains("fields"))
        j["fields"] = nlohmann::json{};

    for (const auto &f : message.fields())
    {
        to_json(j["fields"][f.name()], f);
    }
    if (commsdsl::Protocol::notYetDeprecated() != message.deprecatedSince())
        j["deprecatedSince"] = message.deprecatedSince();
    j["sinceVersion"] = message.sinceVersion();
}
} // namespace protodoc
