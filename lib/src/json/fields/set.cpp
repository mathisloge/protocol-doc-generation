#include "set.hpp"
#include "../endian.hpp"

using namespace protodoc;
namespace commsdsl::parse
{
static void to_json(json_obj &j, const SetField::BitInfo &f)
{
    j.merge_patch({{"index", f.m_idx},
                   {kKeyFieldDisplayName, f.m_displayName},
                   {kKeyFieldDescription, f.m_description},
                   {kKeyFieldSinceVersion, f.m_sinceVersion}});
    if (f.m_deprecatedSince != Protocol::notYetDeprecated())
        j[kKeyFieldDeprecatedSince] = f.m_deprecatedSince;
}
static void to_json(json_obj &j, const SetField::Bits &bits)
{
    for (const auto &b : bits)
        j.merge_patch({b.first, b.second});
}

void to_json(json_obj &j, const SetField &f)
{
    j.merge_patch({{kKeyType, kSetType}, {kKeyEndian, f.endian()}, {"bits", f.bits()}});
}
} // namespace commsdsl::parse
