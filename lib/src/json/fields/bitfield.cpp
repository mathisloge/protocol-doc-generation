#include "bitfield.hpp"
#include "../endian.hpp"
#include "../field.hpp"
#include "../types.hpp"

namespace protodoc
{

void to_json(nlohmann::json &j, const commsdsl::BitfieldField &f)
{
    j[kKeyType] = kBitfieldType;
    j[kKeyEndian] = EndianToString(f.endian());
    for (const auto &member : f.members())
    {
        auto &val_json = j["member"][member.name()];
        to_json(val_json, member);
    }
}

} // namespace protodoc
