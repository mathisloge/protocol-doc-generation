#include "variant.hpp"
#include "../field.hpp"
#include "../types.hpp"
namespace protodoc
{
void to_json(json_obj &j, const commsdsl::VariantField &f)
{
    j[kKeyType] = kVariantType;
    for (const auto &m : f.members())
        to_json(j["members"][m.name()], m);

    if (f.defaultMemberIdx() != std::numeric_limits<decltype(f.defaultMemberIdx())>::max())
        to_json(j["defaultMember"], f.members()[f.defaultMemberIdx()]);
}
} // namespace protodoc
