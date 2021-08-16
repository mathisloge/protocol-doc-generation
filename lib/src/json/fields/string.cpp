#include "string.hpp"
#include "../field.hpp"
#include "../types.hpp"

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::StringField &f)
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
