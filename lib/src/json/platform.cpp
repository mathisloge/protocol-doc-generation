#include "platform.hpp"
namespace protodoc
{
void to_json(json_obj &j, const commsdsl::Protocol::PlatformsList &platforms)
{
    for (const auto &p : platforms)
    {
        j[p]["name"] = p;
    }
}
} // namespace protodoc
