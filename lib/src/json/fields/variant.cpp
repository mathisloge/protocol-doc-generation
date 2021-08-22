#include "variant.hpp"
#include "../types.hpp"
#include "field.hpp"
namespace protodoc
{
void to_json(json_obj &j, const commsdsl::VariantField &f)
{
    j[kKeyType] = kVariantType;
    for (const auto &m : f.members())
        to_json(j[kKeyFieldMembers][m.name()], m);

    if (f.defaultMemberIdx() != std::numeric_limits<decltype(f.defaultMemberIdx())>::max())
        to_json(j["defaultMember"], f.members()[f.defaultMemberIdx()]);
}
} // namespace protodoc
