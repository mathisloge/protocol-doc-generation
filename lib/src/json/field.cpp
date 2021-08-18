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
namespace protodoc
{

void to_json(json_obj &j, const commsdsl::Field &f)
{
    j[kKeyFieldName] = f.name();
    j[kKeyFieldSemanticType] = SemanticTypeToString(f.semanticType());
    j[kKeyFieldKind] = f.kind();
    if (!f.displayName().empty())
        j[kKeyFieldDisplayName] = f.displayName();
    if (!f.description().empty())
        j[kKeyFieldDescription] = f.description();
    if (commsdsl::Protocol::notYetDeprecated() != f.deprecatedSince())
        j[kKeyFieldDeprecatedSince] = f.deprecatedSince();
    if (f.sinceVersion() > 0)
        j[kKeyFieldSinceVersion] = f.sinceVersion();
    j[kKeyFieldMinLength] = f.minLength();
    j[kKeyFieldMaxLength] = f.maxLength();
    switch (f.kind())
    {
    case commsdsl::Field::Kind::Int:
        to_json(j, commsdsl::IntField{f});
        break;
    case commsdsl::Field::Kind::Enum:
        to_json(j, commsdsl::EnumField{f});
        break;
    case commsdsl::Field::Kind::Set:
        to_json(j, commsdsl::SetField{f});
        break;
    case commsdsl::Field::Kind::Float:
        to_json(j, commsdsl::FloatField{f});
        break;
    case commsdsl::Field::Kind::Bitfield:
        to_json(j, commsdsl::BitfieldField{f});
        break;
    case commsdsl::Field::Kind::Bundle:
        to_json(j, commsdsl::BundleField{f});
        break;
    case commsdsl::Field::Kind::String:
        to_json(j, commsdsl::StringField{f});
        break;
    case commsdsl::Field::Kind::Data:
        to_json(j, commsdsl::DataField{f});
        break;
    case commsdsl::Field::Kind::List:
        to_json(j, commsdsl::ListField{f});
        break;
    case commsdsl::Field::Kind::Ref:
        to_json(j, commsdsl::RefField{f});
        break;
    case commsdsl::Field::Kind::Optional:
        to_json(j, commsdsl::OptionalField{f});
        break;
    case commsdsl::Field::Kind::Variant:
        to_json(j, commsdsl::VariantField{f});
        break;
    default:
        j[kKeyType] = "unknown";
        break;
    }
}

} // namespace protodoc
