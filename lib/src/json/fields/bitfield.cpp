#include "bitfield.hpp"
#include "../endian.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl::parse
{
static void to_json(json_obj &j, const BitfieldField::Members &members)
{
    for (const auto &member : members)
        j[member.name()].merge_patch(member);
}

void to_json(json_obj &j, const BitfieldField &f)
{
    j.merge_patch({{kKeyType, kBitfieldType}, {kKeyEndian, f.endian()}, {kKeyFieldMembers, f.members()}});
}

} // namespace commsdsl::parse
