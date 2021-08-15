#include "ref.hpp"
#include "../field.hpp"

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::RefField &f)
{
    to_json(j, f.field());
}
} // namespace protodoc
