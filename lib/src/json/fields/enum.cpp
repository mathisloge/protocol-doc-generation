#include "enum.hpp"
#include "../types.hpp"
namespace protodoc
{

void to_json(json_obj &j, const commsdsl::EnumField &f)
{
    j[kKeyType] = TypeToString(f.type());
    for (const auto &value : f.values())
    {
        auto &val_json = j["enum"][value.first];
        val_json[kKeyFieldName] = value.first;
        if (!value.second.m_displayName.empty())
            val_json[kKeyFieldDisplayName] = value.second.m_displayName;
        val_json["value"] = value.second.m_value;
        if (!value.second.m_description.empty())
            val_json[kKeyFieldDescription] = value.second.m_description;
        if (value.second.m_sinceVersion > 0)
            val_json[kKeyFieldSinceVersion] = value.second.m_sinceVersion;
        if (commsdsl::Protocol::notYetDeprecated() != value.second.m_deprecatedSince)
            j[kKeyFieldDeprecatedSince] = value.second.m_deprecatedSince;
    }
}

} // namespace protodoc
