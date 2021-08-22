#include "bundle.hpp"
#include "../endian.hpp"
#include "../types.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl
{
static void to_json(json_obj &j, const commsdsl::BundleField::Members &members)
{
    for (const auto &m : members)
        j.merge_patch({m.name(), m});
}

void to_json(json_obj &j, const commsdsl::BundleField &f)
{
    j.merge_patch({{kKeyType, kBundleType}, {kKeyFieldMembers, f.members()}});
}
} // namespace commsdsl
