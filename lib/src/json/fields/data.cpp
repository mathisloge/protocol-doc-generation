#include "data.hpp"
#include "../endian.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl
{
void to_json(json_obj &j, const commsdsl::DataField &f)
{
    constexpr const char *kKeyLengthField = "lengthField";
    constexpr const char *kKeyFixedLength = "fixedLength";
    j.merge_patch({{kKeyType, kDataType}, {kKeyFixedLength, f.fixedLength()}});
    if (f.hasLengthPrefixField())
        j[kKeyLengthField].merge_patch(f.lengthPrefixField());
    else if (!f.detachedPrefixFieldName().empty())
        j[kKeyLengthField].merge_patch(f.detachedPrefixFieldName());
}

} // namespace commsdsl
