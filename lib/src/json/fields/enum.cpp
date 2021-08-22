#include "enum.hpp"
#include "../types.hpp"

using namespace protodoc;
namespace commsdsl
{

static void to_json(protodoc::json_obj &j, const commsdsl::EnumField::Values &values)
{
    for (const auto &value : values)
    {
        auto &val_json = j[value.first];
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

void to_json(protodoc::json_obj &j, const commsdsl::EnumField &f)
{
    j.merge_patch({{kKeyType, TypeToString(f.type())}, {"enum", f.values()}});
}

} // namespace commsdsl
