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
#include "types.hpp"
namespace protodoc
{

void to_json(nlohmann::json &j, const commsdsl::Field &f)
{
    j["name"] = f.displayName().empty() ? f.name() : f.displayName();
    j["semanticType"] = SemanticTypeToString(f.semanticType());
    j["kind"] = f.kind();
    if (!f.description().empty())
        j["description"] = f.description();
    if (commsdsl::Protocol::notYetDeprecated() != f.deprecatedSince())
        j["deprecatedSince"] = f.deprecatedSince();
    if (f.sinceVersion() > 0)
        j["sinceVersion"] = f.sinceVersion();
    j["minLength"] = f.minLength();
    j["maxLength"] = f.maxLength();
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

    default:
        j["type"] = "unknown";
        break;
    }
}

} // namespace protodoc
