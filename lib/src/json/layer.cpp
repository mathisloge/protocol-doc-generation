#include "layer.hpp"
#include "field.hpp"
namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::Layer &f)
{
    j["name"] = f.name();
    j["description"] = f.description();
    if (f.hasField())
        to_json(j["field"], f.field());
}
} // namespace protodoc
