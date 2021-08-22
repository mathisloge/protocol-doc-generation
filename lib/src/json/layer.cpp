#include "layer.hpp"
#include "field.hpp"
#include "types.hpp"
namespace protodoc
{
void to_json(json_obj &j, const commsdsl::Layer &f)
{
    j[kKeyFieldName] = f.name();
    if (!f.description().empty())
        j[kKeyFieldDescription] = f.description();
    if (f.hasField())
        to_json(j[kKeyFieldField], f.field());
}
} // namespace protodoc
