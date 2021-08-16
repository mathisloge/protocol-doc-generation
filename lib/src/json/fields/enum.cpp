#include "enum.hpp"
#include "../types.hpp"
namespace protodoc
{

void to_json(nlohmann::json &j, const commsdsl::EnumField &f)
{
    j[kKeyType] = TypeToString(f.type());
    for (const auto &value : f.values())
    {
        auto &val_json = j["enum"][std::to_string(value.second.m_value)];
        val_json["name"] = (!value.second.m_displayName.empty()) ? value.second.m_displayName : value.first;
        val_json["value"] = value.second.m_value;
        if (!value.second.m_description.empty())
            val_json["description"] = value.second.m_description;
        if (value.second.m_sinceVersion > 0)
            val_json["sinceVersion"] = value.second.m_sinceVersion;
        if (commsdsl::Protocol::notYetDeprecated() != value.second.m_deprecatedSince)
            j["deprecatedSince"] = value.second.m_deprecatedSince;
    }
}

} // namespace protodoc
