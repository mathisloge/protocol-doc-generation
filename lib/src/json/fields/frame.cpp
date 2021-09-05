#include "frame.hpp"
#include "layer.hpp"

using namespace protodoc;
namespace commsdsl
{

void to_json(json_obj &j, const commsdsl::Frame &f)
{
    j.merge_patch({{kKeyFieldName, f.name()}, {kKeyFieldDescription, f.description()}, {kKeyFields, f.layers()}});
}
void to_json(json_obj &j, const commsdsl::Frame::LayersList &f)
{
    for (const auto &layer : f)
        j[layer.name()] = layer;
}

} // namespace commsdsl
