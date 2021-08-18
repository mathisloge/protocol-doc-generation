#include "set.hpp"
#include "../endian.hpp"
#include "../types.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::SetField::BitInfo &f)
{
    j["index"] = f.m_idx;
    j["displayName"] = f.m_displayName;
    j["description"] = f.m_description;
    j["sinceVersion"] = f.m_sinceVersion;
    if (f.m_deprecatedSince != commsdsl::Protocol::notYetDeprecated())
        j["deprecatedSince"] = f.m_deprecatedSince;
}

void to_json(json_obj &j, const commsdsl::SetField &f)
{
    j[kKeyType] = kSetType;
    j[kKeyEndian] = EndianToString(f.endian());

    for (const auto &b : f.bits())
    {
        to_json(j["bits"][b.first], b.second);
    }
}
} // namespace protodoc
