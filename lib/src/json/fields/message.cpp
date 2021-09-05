#include "message.hpp"
#include <commsdsl/Protocol.h>
#include "field.hpp"

using namespace protodoc;
namespace commsdsl
{
static void to_json(protodoc::json_obj &j, const commsdsl::Message::FieldsList &fields)
{
    for (const auto &f : fields)
        j[f.name()] = f;
}

void to_json(protodoc::json_obj &j, const commsdsl::Message &message)
{
    j.merge_patch({{kKeyFieldName, message.name()},
                   {kKeyFieldDisplayName, message.displayName()},
                   {kKeyFieldDescription, message.description()},
                   {kKeyFields, message.fields()}});
    if (commsdsl::Protocol::notYetDeprecated() != message.deprecatedSince())
        j[kKeyFieldDeprecatedSince] = message.deprecatedSince();
    j[kKeyFieldSinceVersion] = message.sinceVersion();
}
} // namespace commsdsl
