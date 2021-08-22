#include "bitfield.hpp"
#include "../endian.hpp"
#include "../types.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl
{
static void to_json(json_obj &j, const commsdsl::BitfieldField::Members &members)
{
    for (const auto &member : members)
        j[member.name()].merge_patch(member);
}

void to_json(json_obj &j, const commsdsl::BitfieldField &f)
{
    j.merge_patch(
        {{kKeyType, kBitfieldType}, {kKeyEndian, EndianToString(f.endian())}, {kKeyFieldMembers, f.members()}});
}

} // namespace commsdsl
