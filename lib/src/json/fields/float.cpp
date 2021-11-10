#include "float.hpp"
#include "../endian.hpp"
#include "../units.hpp"

using namespace protodoc;
namespace commsdsl
{
using Type = FloatField::Type;
NLOHMANN_JSON_SERIALIZE_ENUM(
    Type, {{Type::Float, "float"}, {Type::Double, "double"}, {Type::NumOfValues, protodoc::keyValueUnknown}});

static void to_json(json_obj &j, const commsdsl::FloatField::ValidRangesList &ranges)
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
void to_json(json_obj &j, const commsdsl::FloatField &f)
{
    j.merge_patch({{kKeyType, kFloatType}, {kKeyEndian, f.endian()}, {kKeyFieldRange, f.validRanges()}});
    if (f.units() != commsdsl::Units::Unknown && f.units() < commsdsl::Units::NumOfValues)
        j[kKeyFieldUnits] = f.units();
}

} // namespace commsdsl
