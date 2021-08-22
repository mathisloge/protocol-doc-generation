#include "string.hpp"
#include "../types.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::StringField &f)
{
    j.merge_patch({{kKeyType, kStringType}});
    j[kKeyType] = kStringType;

    if (f.hasLengthPrefixField())
    {
        if (f.detachedPrefixFieldName().empty())
            j["lengthField"].merge_patch(f.lengthPrefixField());
        else
            j["lengthField"].merge_patch(f.detachedPrefixFieldName());
    }
    else if (f.hasZeroTermSuffix())
        j["zeroTerminated"].merge_patch(f.hasZeroTermSuffix());
    else
        j["fixedLength"].merge_patch(f.fixedLength());
}
} // namespace commsdsl
