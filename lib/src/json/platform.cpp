#include "platform.hpp"
namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::Protocol::PlatformsList &platforms)
{
    for (const auto &p : platforms)
    {
        j[p]["name"] = p;
    }
}
} // namespace protodoc
