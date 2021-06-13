#include "field.hpp"
#include "enum.hpp"
namespace protodoc
{

void to_json(nlohmann::json &j, const commsdsl::Field &f)
{
    j["name"] = f.displayName().empty() ? f.name() : f.displayName();
    j["description"] = f.description();
    switch (f.kind())
    {
    case commsdsl::Field::Kind::Enum:
        to_json(j, commsdsl::EnumField{f});
        break;

    default:
        break;
    }
}

} // namespace protodoc
