#include "platform.hpp"

using namespace protodoc;
namespace commsdsl::parse
{
void to_json(json_obj &j, const Protocol::PlatformsList &platforms)
{
    for (const auto &p : platforms)
        j[p][kKeyFieldName] = p;
}
} // namespace commsdsl::parse
