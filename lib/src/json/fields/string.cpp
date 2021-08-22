#include "string.hpp"
#include "../types.hpp"
#include "field.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::StringField &f)
{
    j[kKeyType] = kStringType;

    if (f.hasLengthPrefixField())
    {
        if (f.detachedPrefixFieldName().empty())
            to_json(j["lengthField"], f.lengthPrefixField());
        else
            j["lengthField"] = f.detachedPrefixFieldName();
    }
    else if (f.hasZeroTermSuffix())
        j["zeroTerminated"] = f.hasZeroTermSuffix();
    else
        j["fixedLength"] = f.fixedLength();
}
} // namespace protodoc
