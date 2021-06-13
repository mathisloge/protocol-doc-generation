#include "frame.hpp"
#include "layer.hpp"
namespace protodoc
{

void to_json(nlohmann::json &j, const commsdsl::Frame &f)
{
    j["name"] = f.name();
    j["description"] = f.description();
    to_json(j["fields"], f.layers());
}

void to_json(nlohmann::json &j, const commsdsl::Frame::LayersList &f)
{
    if (!j.is_array())
    {
        j = nlohmann::json::array();
    }
    for(const auto& layer : f) {
        to_json(j.emplace_back(), layer);
    }
}

} // namespace protodoc
