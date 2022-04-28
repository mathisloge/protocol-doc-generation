#include "enum.hpp"

using namespace protodoc;
namespace commsdsl::parse
{

static void to_json(protodoc::json_obj &j, const EnumField::Values &values)
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
        if (Protocol::notYetDeprecated() != value.second.m_deprecatedSince)
            val_json[kKeyFieldDeprecatedSince] = value.second.m_deprecatedSince;
    }
}

void to_json(protodoc::json_obj &j, const EnumField &f)
{
    j.merge_patch({{kKeyType, kEnumType}, {"enum", f.values()}});
}

} // namespace commsdsl::parse
