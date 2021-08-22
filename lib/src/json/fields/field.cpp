#include "field.hpp"
#include "../types.hpp"
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
        j[kKeyType] = keyValueUnknown;
        break;
    }
}

} // namespace commsdsl