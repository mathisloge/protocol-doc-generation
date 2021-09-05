#include "variant.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl
{
static void to_json(json_obj &j, const commsdsl::VariantField::Members &members)
{
    for (const auto &m : members)
        j[m.name()].merge_patch(m);
}

void to_json(json_obj &j, const commsdsl::VariantField &f)
{
    j.merge_patch({{kKeyType, kVariantType}, kKeyFieldMembers, f.members()});
    if (f.defaultMemberIdx() != std::numeric_limits<decltype(f.defaultMemberIdx())>::max())
        j["defaultMember"].merge_patch(f.members()[f.defaultMemberIdx()]);
}
} // namespace commsdsl
