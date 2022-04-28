#include "ref.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const RefField &f)
{
    j.merge_patch({{kKeyType, kRefType}, {kKeyFieldField, f.field().name()}});
}
} // namespace commsdsl::parse
