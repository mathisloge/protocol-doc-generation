#include "ref.hpp"
#include "../types.hpp"
#include "field.hpp"
namespace protodoc
{
void to_json(json_obj &j, const commsdsl::RefField &f)
{
    j[kKeyType] = kRefType;
    j[kKeyFieldField] = f.field().name();
}
} // namespace protodoc
