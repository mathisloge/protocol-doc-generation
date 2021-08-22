#include "layer.hpp"
#include "../types.hpp"
#include "field.hpp"

using namespace protodoc;
namespace commsdsl
{
void to_json(json_obj &j, const commsdsl::Layer &f)
{
    j.merge_patch({{kKeyFieldName, f.name()}, {kKeyFieldDescription, f.description()}});
    if (f.hasField())
        j[kKeyFieldField] = f.field();
}
} // namespace commsdsl
