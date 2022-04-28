#include "int.hpp"
#include "../endian.hpp"
#include "../units.hpp"
#include <cpp-json-schema/schema.hpp>

using namespace protodoc;
namespace commsdsl::parse
{
using Type = IntField::Type;
NLOHMANN_JSON_SERIALIZE_ENUM(Type,
                             {{Type::Int8, "int8"},
                              {Type::Uint8, "uint8"},
                              {Type::Int16, "int16"},
                              {Type::Uint16, "uint16"},
                              {Type::Int32, "int32"},
                              {Type::Uint32, "uint32"},
                              {Type::Int64, "int64"},
                              {Type::Uint64, "uint64"},
                              {Type::Intvar, "intvar"},
                              {Type::Uintvar, "uintvar"},
                              {Type::NumOfValues, protodoc::keyValueUnknown}});

static void to_json(json_obj &j, const IntField::ValidRangesList &ranges)
{
    for (const auto &range : ranges)
    {
        auto &jrange = j.emplace_back(json_obj{{"min", range.m_min}, {"max", range.m_max}});
        if (range.m_sinceVersion > 0)
            jrange[kKeyFieldSinceVersion] = range.m_sinceVersion;
        if (range.m_deprecatedSince < Protocol::notYetDeprecated())
            jrange[kKeyFieldDeprecatedSince] = range.m_deprecatedSince;
    }
}
void to_json(json_obj &j, const IntField &f)
{
    j.merge_patch({{kKeyType, kIntType},
                   {kKeyEndian, f.endian()},
                   {kKeyFieldScaling, f.scaling()},
                   {kKeyFieldRange, f.validRanges()}});
    if (f.units() != Units::Unknown && f.units() < Units::NumOfValues)
        j[kKeyFieldUnits] = f.units();
}

} // namespace commsdsl::parse

namespace protodoc
{
void generateIntFieldSchema(const std::string &base_url)
{
    using namespace schema;
    JsonSchema schema{base_url, "intField"};

    JsonSchemaObjectProperty schema_obj{schema.json()};
    schema_obj.init();

    schema_obj.addAllOf<JsonSchemaRefProperty>().setRef(base_url, "field");

    schema.setTitle("IntField");
    schema.write(".");
}
} // namespace protodoc
