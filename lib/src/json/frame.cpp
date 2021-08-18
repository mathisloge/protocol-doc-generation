#include "frame.hpp"
#include "layer.hpp"
namespace protodoc
{

void to_json(json_obj &j, const commsdsl::Frame &f)
{
    j["name"] = f.name();
    j["description"] = f.description();
    to_json(j["fields"], f.layers());
}

void to_json(json_obj &j, const commsdsl::Frame::LayersList &f)
{
    for (const auto &layer : f)
    {
        to_json(j[layer.name()], layer);
    }
}

} // namespace protodoc
