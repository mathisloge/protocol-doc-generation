#include "enum.hpp"
#include "../types.hpp"

using namespace protodoc;
namespace commsdsl
{

static void to_json(protodoc::json_obj &j, const commsdsl::EnumField::Values &values)
{
    for (const auto &value : values)
    {
        j[value.first].merge_patch({{kKeyFieldName, value.first},
                                    {kKeyFieldDisplayName, value.second.m_displayName},
                                    {kKeyFieldDescription, value.second.m_description},
                                    {kKeyValue, value.second.m_value}});
        auto &val_json = j[value.first];
        if (value.second.m_sinceVersion > 0)
            val_json[kKeyFieldSinceVersion] = value.second.m_sinceVersion;
        if (commsdsl::Protocol::notYetDeprecated() != value.second.m_deprecatedSince)
            val_json[kKeyFieldDeprecatedSince] = value.second.m_deprecatedSince;
    }
}

void to_json(protodoc::json_obj &j, const commsdsl::EnumField &f)
{
    j.merge_patch({{kKeyType, TypeToString(f.type())}, {"enum", f.values()}});
}

} // namespace commsdsl
