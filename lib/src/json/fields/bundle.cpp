#include "bundle.hpp"
#include "../endian.hpp"
#include "../types.hpp"
#include "field.hpp"

namespace protodoc
{

void to_json(json_obj &j, const commsdsl::BundleField &f)
{
    j[kKeyType] = kBundleType;

    for (const auto &m : f.members())
        to_json(j[kKeyFieldMembers][m.name()], m);
}

} // namespace protodoc
