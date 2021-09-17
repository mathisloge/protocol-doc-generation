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
namespace commsdsl
{

void to_json(json_obj &j, const commsdsl::Field &f)
{
    j.merge_patch({{kKeyFieldName, f.name()},
                   {kKeyFieldDisplayName, f.displayName()},
                   {kKeyFieldDescription, f.description()},
                   {kKeyFieldSemanticType, f.semanticType()},
                   {kKeyFieldKind, f.kind()},
                   {kKeyFieldMaxLength, f.minLength()},
                   {kKeyFieldMaxLength, f.maxLength()}});

    if (commsdsl::Protocol::notYetDeprecated() != f.deprecatedSince())
        j[kKeyFieldDeprecatedSince] = f.deprecatedSince();
    if (f.sinceVersion() > 0)
        j[kKeyFieldSinceVersion] = f.sinceVersion();
    switch (f.kind())
    {
    case commsdsl::Field::Kind::Int:
        j.merge_patch(commsdsl::IntField{f});
        break;
    case commsdsl::Field::Kind::Enum:
        j.merge_patch(commsdsl::EnumField{f});
        break;
    case commsdsl::Field::Kind::Set:
        j.merge_patch(commsdsl::SetField{f});
        break;
    case commsdsl::Field::Kind::Float:
        j.merge_patch(commsdsl::FloatField{f});
        break;
    case commsdsl::Field::Kind::Bitfield:
        j.merge_patch(commsdsl::BitfieldField{f});
        break;
    case commsdsl::Field::Kind::Bundle:
        j.merge_patch(commsdsl::BundleField{f});
        break;
    case commsdsl::Field::Kind::String:
        j.merge_patch(commsdsl::StringField{f});
        break;
    case commsdsl::Field::Kind::Data:
        j.merge_patch(commsdsl::DataField{f});
        break;
    case commsdsl::Field::Kind::List:
        j.merge_patch(commsdsl::ListField{f});
        break;
    case commsdsl::Field::Kind::Ref:
        j.merge_patch(commsdsl::RefField{f});
        break;
    case commsdsl::Field::Kind::Optional:
        j.merge_patch(commsdsl::OptionalField{f});
        break;
    case commsdsl::Field::Kind::Variant:
        j.merge_patch(commsdsl::VariantField{f});
        break;
    default:
        j[kKeyFieldKind] = keyValueUnknown;
        break;
    }
}

} // namespace commsdsl

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
        .addValue(commsdsl::Field::SemanticType::None)
        .addValue(commsdsl::Field::SemanticType::Version)
        .addValue(commsdsl::Field::SemanticType::MessageId)
        .addValue(commsdsl::Field::SemanticType::Length)
        .addValue(commsdsl::Field::SemanticType::NumOfValues) //! unknown value
        ;
    schema_obj.addProperty<JsonSchemaEnumProperty>(kKeyFieldKind, "field kind", true)
        .addValue(commsdsl::Field::Kind::Int)
        .addValue(commsdsl::Field::Kind::Enum)
        .addValue(commsdsl::Field::Kind::Set)
        .addValue(commsdsl::Field::Kind::Float)
        .addValue(commsdsl::Field::Kind::Bitfield)
        .addValue(commsdsl::Field::Kind::Bundle)
        .addValue(commsdsl::Field::Kind::String)
        .addValue(commsdsl::Field::Kind::Data)
        .addValue(commsdsl::Field::Kind::List)
        .addValue(commsdsl::Field::Kind::Ref)
        .addValue(commsdsl::Field::Kind::Optional)
        .addValue(commsdsl::Field::Kind::Variant)
        .addValue(commsdsl::Field::Kind::NumOfValues);
    schema_obj.addProperty<JsonSchemaNumberProperty>(kKeyFieldDeprecatedSince, "deprecated since version", false);
    schema_obj.addProperty<JsonSchemaNumberProperty>(kKeyFieldSinceVersion, "available since version", false);

    schema.setTitle("Field");
    schema.write(".");
}
} // namespace protodoc
