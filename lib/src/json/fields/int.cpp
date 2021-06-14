#include "int.hpp"
namespace protodoc
{

void to_json(nlohmann::json &j, const commsdsl::IntField &f)
{
    j["scaling"] = f.scaling();
}

} // namespace protodoc
