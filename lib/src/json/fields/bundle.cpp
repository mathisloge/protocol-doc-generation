#include "bundle.hpp"
#include "../endian.hpp"
#include "../field.hpp"
#include "../types.hpp"

namespace protodoc
{

void to_json(nlohmann::json &j, const commsdsl::BundleField &f)
{
    j["type"] = kBundleType;

    for (const auto &m : f.members())
        to_json(j["members"][m.name()], m);
}

} // namespace protodoc