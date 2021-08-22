#include "int.hpp"
#include "../endian.hpp"
#include "../types.hpp"
#include "../units.hpp"

using namespace protodoc;
namespace commsdsl
{
static void to_json(json_obj &j, const commsdsl::IntField::ValidRangesList &ranges)
{
    for (const auto &range : ranges)
    {
        auto &jrange = j.emplace_back(json_obj{{"min", range.m_min}, {"max", range.m_max}});
        if (range.m_sinceVersion > 0)
            jrange[kKeyFieldSinceVersion] = range.m_sinceVersion;
        if (range.m_deprecatedSince < commsdsl::Protocol::notYetDeprecated())
            jrange[kKeyFieldDeprecatedSince] = range.m_deprecatedSince;
    }
}
void to_json(json_obj &j, const commsdsl::IntField &f)
{
    j.merge_patch({{kKeyType, TypeToString(f.type())},
                   {kKeyEndian, EndianToString(f.endian())},
                   {kKeyFieldScaling, f.scaling()},
                   {kKeyFieldRange, f.validRanges()}});
    if (f.units() != commsdsl::Units::Unknown && f.units() < commsdsl::Units::NumOfValues)
        j[kKeyFieldUnits] = UnitsToString(f.units());
}

} // namespace commsdsl
