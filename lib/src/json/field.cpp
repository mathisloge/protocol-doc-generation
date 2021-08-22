#include "field.hpp"
#include "fields/bitfield.hpp"
#include "fields/bundle.hpp"
#include "fields/data.hpp"
#include "fields/enum.hpp"
#include "fields/float.hpp"
#include "fields/int.hpp"
#include "fields/list.hpp"
#include "fields/optional.hpp"
#include "fields/ref.hpp"
#include "fields/set.hpp"
#include "fields/string.hpp"
#include "fields/variant.hpp"
#include "types.hpp"

using namespace protodoc;
namespace commsdsl
{

void to_json(json_obj &j, const commsdsl::Field &f)
{
    j.merge_patch({{kKeyFieldName, f.name()},
                   {kKeyFieldDisplayName, f.displayName()},
                   {kKeyFieldDescription, f.description()},
                   {kKeyFieldSemanticType, SemanticTypeToString(f.semanticType())},
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
        protodoc::to_json(j, commsdsl::IntField{f});
        break;
    case commsdsl::Field::Kind::Enum:
        protodoc::to_json(j, commsdsl::EnumField{f});
        break;
    case commsdsl::Field::Kind::Set:
        protodoc::to_json(j, commsdsl::SetField{f});
        break;
    case commsdsl::Field::Kind::Float:
        protodoc::to_json(j, commsdsl::FloatField{f});
        break;
    case commsdsl::Field::Kind::Bitfield:
        protodoc::to_json(j, commsdsl::BitfieldField{f});
        break;
    case commsdsl::Field::Kind::Bundle:
        protodoc::to_json(j, commsdsl::BundleField{f});
        break;
    case commsdsl::Field::Kind::String:
        protodoc::to_json(j, commsdsl::StringField{f});
        break;
    case commsdsl::Field::Kind::Data:
        protodoc::to_json(j, commsdsl::DataField{f});
        break;
    case commsdsl::Field::Kind::List:
        protodoc::to_json(j, commsdsl::ListField{f});
        break;
    case commsdsl::Field::Kind::Ref:
        protodoc::to_json(j, commsdsl::RefField{f});
        break;
    case commsdsl::Field::Kind::Optional:
        protodoc::to_json(j, commsdsl::OptionalField{f});
        break;
    case commsdsl::Field::Kind::Variant:
        protodoc::to_json(j, commsdsl::VariantField{f});
        break;
    default:
        j[kKeyType] = keyValueUnknown;
        break;
    }
}

} // namespace commsdsl
