#include "bundle.hpp"
#include "../endian.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl::parse
{
static void to_json(json_obj &j, const BundleField::Members &members)
{
    for (const auto &m : members)
        j.merge_patch({m.name(), m});
}

void to_json(json_obj &j, const BundleField &f)
{
    j.merge_patch({{kKeyType, kBundleType}, {kKeyFieldMembers, f.members()}});
}
} // namespace commsdsl::parse
