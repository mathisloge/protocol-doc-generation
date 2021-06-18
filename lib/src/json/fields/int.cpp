#include "int.hpp"
#include "../units.hpp"
namespace protodoc
{

void to_json(nlohmann::json &j, const commsdsl::IntField &f)
{
    j["scaling"] = f.scaling();
    if (f.units() != commsdsl::Units::Unknown && f.units() < commsdsl::Units::NumOfValues)
    {
        j["units"] = UnitsToString(f.units());
    }
}

} // namespace protodoc
