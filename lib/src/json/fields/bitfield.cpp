#include "bitfield.hpp"
#include "../endian.hpp"
#include "field_vector.hpp"

using namespace protodoc;
namespace commsdsl::parse
{

void to_json(json_obj &j, const BitfieldField &f)
{
    j.merge_patch({{kKeyType, kBitfieldType}, {kKeyEndian, f.endian()}, {kKeyFieldMembers, f.members()}});
}

} // namespace commsdsl::parse
