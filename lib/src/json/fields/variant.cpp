#include "variant.hpp"
#include "field.hpp"
#include "field_vector.hpp"

using namespace protodoc;
namespace commsdsl::parse
{
void to_json(json_obj &j, const VariantField &f)
{
    const auto members = f.members();
    j.merge_patch({{kKeyType, kVariantType}, kKeyFieldMembers, members});
    if (f.defaultMemberIdx() != std::numeric_limits<decltype(f.defaultMemberIdx())>::max())
        j["defaultMember"].merge_patch(members[f.defaultMemberIdx()]);
}
} // namespace commsdsl::parse
