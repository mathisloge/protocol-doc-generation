#include "field_vector.hpp"
#include "field.hpp"
using namespace protodoc;
namespace commsdsl::parse
{
void to_json(json_obj &j, const std::vector<Field> &fields)
{
    uint32_t idx = 0;
    for (const auto &field : fields)
    {
        json_obj json_field = json_obj::object();
        json_field[kKeyOrderIndex] = idx;
        json_field.merge_patch(field);
        j[field.name()].merge_patch(json_field);
        idx++;
    }
}
} // namespace commsdsl::parse
