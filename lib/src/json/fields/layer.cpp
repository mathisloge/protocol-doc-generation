#include "layer.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl::parse
{
void to_json(json_obj &j, const Layer &f)
{
    j.merge_patch({{kKeyFieldName, f.name()}, {kKeyFieldDescription, f.description()}});
    if (f.hasField())
        j[kKeyFieldField] = f.field();
}
} // namespace commsdsl::parse
