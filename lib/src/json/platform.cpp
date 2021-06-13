#include "platform.hpp"
namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::Protocol::PlatformsList &platforms)
{
    for (int i = 0; i < platforms.size(); i++)
    {
        if (j.size() <= i)
        {
            j.emplace_back();
        }
        j[i]["name"] = platforms[i];
    }
}
} // namespace protodoc
