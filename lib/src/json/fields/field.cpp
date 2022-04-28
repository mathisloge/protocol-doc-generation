#include "field.hpp"
#include "bitfield.hpp"
#include "bundle.hpp"
#include "data.hpp"
#include "enum.hpp"
#include "float.hpp"
#include "int.hpp"
#include "list.hpp"
#include "optional.hpp"
#include "ref.hpp"
#include "set.hpp"
#include "string.hpp"
#include "variant.hpp"
#include <cpp-json-schema/schema.hpp>

using namespace protodoc;
namespace commsdsl::parse
{

void to_json(json_obj &j, const Field &f)
{
    j.merge_patch({{kKeyFieldName, f.name()},
                   {kKeyFieldDisplayName, f.displayName()},
                   {kKeyFieldDescription, f.description()},
                   {kKeyFieldSemanticType, f.semanticType()},
                   {kKeyFieldKind, f.kind()},
                   {kKeyFieldMaxLength, f.minLength()},
                   {kKeyFieldMaxLength, f.maxLength()}});

    if (Protocol::notYetDeprecated() != f.deprecatedSince())
        j[kKeyFieldDeprecatedSince] = f.deprecatedSince();
    if (f.sinceVersion() > 0)
        j[kKeyFieldSinceVersion] = f.sinceVersion();
    switch (f.kind())
    {
    case Field::Kind::Int:
        j.merge_patch(IntField{f});
        break;
    case Field::Kind::Enum:
        j.merge_patch(EnumField{f});
        break;
    case Field::Kind::Set:
        j.merge_patch(SetField{f});
        break;
    case Field::Kind::Float:
        j.merge_patch(FloatField{f});
        break;
    case Field::Kind::Bitfield:
        j.merge_patch(BitfieldField{f});
        break;
    case Field::Kind::Bundle:
        j.merge_patch(BundleField{f});
        break;
    case Field::Kind::String:
        j.merge_patch(StringField{f});
        break;
    case Field::Kind::Data:
        j.merge_patch(DataField{f});
        break;
    case Field::Kind::List:
        j.merge_patch(ListField{f});
        break;
    case Field::Kind::Ref:
        j.merge_patch(RefField{f});
        break;
    case Field::Kind::Optional:
        j.merge_patch(OptionalField{f});
        break;
    case Field::Kind::Variant:
        j.merge_patch(VariantField{f});
        break;
    default:
        j[kKeyFieldKind] = keyValueUnknown;
        break;
    }
}

} // namespace commsdsl::parse

namespace protodoc
{
void generateFieldSchema(const std::string &base_url)
{
    using namespace schema;
    JsonSchema schema{base_url, "field"};

    JsonSchemaObjectProperty schema_obj{schema.json()};
    schema_obj.init();

    schema_obj.addProperty<JsonSchemaStringProperty>(kKeyFieldName, "unique name of the field", true);
    schema_obj.addProperty<JsonSchemaStringProperty>(kKeyFieldDisplayName, "human readable name of the field", false);
    schema_obj.addProperty<JsonSchemaStringProperty>(kKeyFieldDescription, "description of the field", false);
    schema_obj.addProperty<JsonSchemaEnumProperty>(kKeyFieldSemanticType, "semantic type", true)
        .addValue(commsdsl::parse::Field::SemanticType::None)
        .addValue(commsdsl::parse::Field::SemanticType::Version)
        .addValue(commsdsl::parse::Field::SemanticType::MessageId)
        .addValue(commsdsl::parse::Field::SemanticType::Length)
        .addValue(commsdsl::parse::Field::SemanticType::NumOfValues) //! unknown value
        ;
    schema_obj.addProperty<JsonSchemaEnumProperty>(kKeyFieldKind, "field kind", true)
        .addValue(commsdsl::parse::Field::Kind::Int)
        .addValue(commsdsl::parse::Field::Kind::Enum)
        .addValue(commsdsl::parse::Field::Kind::Set)
        .addValue(commsdsl::parse::Field::Kind::Float)
        .addValue(commsdsl::parse::Field::Kind::Bitfield)
        .addValue(commsdsl::parse::Field::Kind::Bundle)
        .addValue(commsdsl::parse::Field::Kind::String)
        .addValue(commsdsl::parse::Field::Kind::Data)
        .addValue(commsdsl::parse::Field::Kind::List)
        .addValue(commsdsl::parse::Field::Kind::Ref)
        .addValue(commsdsl::parse::Field::Kind::Optional)
        .addValue(commsdsl::parse::Field::Kind::Variant)
        .addValue(commsdsl::parse::Field::Kind::NumOfValues);
    schema_obj.addProperty<JsonSchemaNumberProperty>(kKeyFieldDeprecatedSince, "deprecated since version", false);
    schema_obj.addProperty<JsonSchemaNumberProperty>(kKeyFieldSinceVersion, "available since version", false);

    schema.setTitle("Field");
    schema.write(".");
}
} // namespace protodoc
