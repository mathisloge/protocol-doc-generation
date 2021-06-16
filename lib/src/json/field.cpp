#include "field.hpp"
#include "fields/enum.hpp"
#include "fields/int.hpp"
namespace protodoc
{

void to_json(nlohmann::json &j, const commsdsl::Field &f)
{
    j["name"] = f.displayName().empty() ? f.name() : f.displayName();
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
    case commsdsl::Field::Kind::Enum:
        to_json(j, commsdsl::EnumField{f});
        break;
    case commsdsl::Field::Kind::Int:
        to_json(j, commsdsl::IntField{f});
        break;
    default:
        break;
    }
}

} // namespace protodoc
