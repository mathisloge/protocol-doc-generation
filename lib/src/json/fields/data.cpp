#include "data.hpp"
#include "../endian.hpp"
#include "../field.hpp"
#include "../types.hpp"

namespace protodoc
{

void to_json(nlohmann::json &j, const commsdsl::DataField &f)
{
    j[kKeyType] = kDataType;
    if (f.hasLengthPrefixField())
        to_json(j["lengthField"], f.lengthPrefixField());
    else if (!f.detachedPrefixFieldName().empty())
        j["lengthField"] = f.detachedPrefixFieldName();
    j["fixedLength"] = f.fixedLength();
}

} // namespace protodoc
