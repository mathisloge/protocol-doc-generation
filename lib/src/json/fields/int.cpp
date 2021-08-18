#include "int.hpp"
#include "../endian.hpp"
#include "../types.hpp"
#include "../units.hpp"

namespace protodoc
{

void to_json(json_obj &j, const commsdsl::IntField &f)
{
    j[kKeyType] = TypeToString(f.type());
    j[kKeyEndian] = EndianToString(f.endian());
    j["scaling"] = f.scaling();
    if (f.units() != commsdsl::Units::Unknown && f.units() < commsdsl::Units::NumOfValues)
    {
        j["units"] = UnitsToString(f.units());
    }

    if (!j["range"].is_array())
        j["range"] = json_obj::array();
    for (const auto &range : f.validRanges())
    {
        auto &jrange = j["range"].emplace_back(json_obj({{"min", range.m_min}, {"max", range.m_max}}));
        if (range.m_sinceVersion > 0)
            jrange["sinceVersion"] = range.m_sinceVersion;
        if (range.m_deprecatedSince < commsdsl::Protocol::notYetDeprecated())
            jrange["deprecatedSince"] = range.m_deprecatedSince;
    }
}

} // namespace protodoc
