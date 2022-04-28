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
    {
        json_obj bit_json = b.second;
        bit_json.merge_patch({{kKeyFieldName, b.first}});
        j[b.first].merge_patch(bit_json);
    }
}

void to_json(json_obj &j, const SetField &f)
{
    j.merge_patch({{kKeyType, kSetType}, {kKeyEndian, f.endian()}, {"bits", f.bits()}});
}
} // namespace commsdsl::parse
