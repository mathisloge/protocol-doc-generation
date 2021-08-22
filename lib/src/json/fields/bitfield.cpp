#include "bitfield.hpp"
#include "../endian.hpp"
#include "../types.hpp"
#include "field.hpp"

namespace protodoc
{

void to_json(json_obj &j, const commsdsl::BitfieldField &f)
{
    j[kKeyType] = kBitfieldType;
    j[kKeyEndian] = EndianToString(f.endian());
    for (const auto &member : f.members())
    {
        auto &val_json = j[kKeyFieldMembers][member.name()];
        to_json(val_json, member);
    }
}

} // namespace protodoc
