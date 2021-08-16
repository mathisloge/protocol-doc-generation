#include "float.hpp"
#include "../types.hpp"
#include "../units.hpp"
#include "../endian.hpp"

namespace protodoc
{

void to_json(nlohmann::json &j, const commsdsl::FloatField &f)
{
    j[kKeyType] = TypeToString(f.type());
    j[kKeyEndian] = EndianToString(f.endian());
    if (f.units() != commsdsl::Units::Unknown && f.units() < commsdsl::Units::NumOfValues)
    {
        j["units"] = UnitsToString(f.units());
    }

    if (!j["range"].is_array())
        j["range"] = nlohmann::json::array();
    for (const auto &range : f.validRanges())
    {
        auto &jrange = j["range"].emplace_back(nlohmann::json({{"min", range.m_min}, {"max", range.m_max}}));
        if (range.m_sinceVersion > 0)
            jrange["sinceVersion"] = range.m_sinceVersion;
        if (range.m_deprecatedSince < commsdsl::Protocol::notYetDeprecated())
            jrange["deprecatedSince"] = range.m_deprecatedSince;
    }
}

} // namespace protodoc
