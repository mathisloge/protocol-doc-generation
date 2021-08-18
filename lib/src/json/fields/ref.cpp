#include "ref.hpp"
#include "../field.hpp"
#include "../types.hpp"
namespace protodoc
{
void to_json(json_obj &j, const commsdsl::RefField &f)
{
    j["type"] = kRefType;
    to_json(j["field"], f.field());
}
} // namespace protodoc
