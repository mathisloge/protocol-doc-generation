#include "frame.hpp"
#include "layer.hpp"
#include "types.hpp"
namespace protodoc
{

void to_json(json_obj &j, const commsdsl::Frame &f)
{
    j[kKeyFieldName] = f.name();
    if (!f.description().empty())
        j[kKeyFieldDescription] = f.description();
    to_json(j[kKeyFields], f.layers());
}

void to_json(json_obj &j, const commsdsl::Frame::LayersList &f)
{
    for (const auto &layer : f)
    {
        to_json(j[layer.name()], layer);
    }
}

} // namespace protodoc
