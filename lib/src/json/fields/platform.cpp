#include "platform.hpp"
namespace protodoc
{
void platforms_to_json(protodoc::json_obj &j, const commsdsl::parse::Protocol::PlatformsList &platforms)
{
    for (const auto &p : platforms)
    {
        json_obj plat_json = json_obj::object();
        plat_json[kKeyFieldName] = p;
        j[p].merge_patch(plat_json);
    }
}
} // namespace protodoc
