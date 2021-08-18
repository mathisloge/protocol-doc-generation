#include "set.hpp"
#include "../endian.hpp"
#include "../types.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::SetField::BitInfo &f)
{
    j["index"] = f.m_idx;
    j[kKeyFieldDisplayName] = f.m_displayName;
    j[kKeyFieldDescription] = f.m_description;
    j[kKeyFieldSinceVersion] = f.m_sinceVersion;
    if (f.m_deprecatedSince != commsdsl::Protocol::notYetDeprecated())
        j[kKeyFieldDeprecatedSince] = f.m_deprecatedSince;
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
