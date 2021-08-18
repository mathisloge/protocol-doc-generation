#include "float.hpp"
#include "../endian.hpp"
#include "../types.hpp"
#include "../units.hpp"

namespace protodoc
{

void to_json(json_obj &j, const commsdsl::FloatField &f)
{
    j[kKeyType] = TypeToString(f.type());
    j[kKeyEndian] = EndianToString(f.endian());
    if (f.units() != commsdsl::Units::Unknown && f.units() < commsdsl::Units::NumOfValues)
    {
        j[kKeyFieldUnits] = UnitsToString(f.units());
    }

    if (!j[kKeyFieldRange].is_array())
        j[kKeyFieldRange] = json_obj::array();
    for (const auto &range : f.validRanges())
    {
        auto &jrange = j[kKeyFieldRange].emplace_back(json_obj({{"min", range.m_min}, {"max", range.m_max}}));
        if (range.m_sinceVersion > 0)
            jrange[kKeyFieldSinceVersion] = range.m_sinceVersion;
        if (range.m_deprecatedSince < commsdsl::Protocol::notYetDeprecated())
            jrange[kKeyFieldDeprecatedSince] = range.m_deprecatedSince;
    }
}

} // namespace protodoc
