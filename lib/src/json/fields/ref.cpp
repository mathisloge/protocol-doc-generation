#include "ref.hpp"
#include "../types.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::RefField &f)
{
    j.merge_patch({{kKeyType, kRefType}, {kKeyFieldField, f.field().name()}});
}
} // namespace commsdsl
