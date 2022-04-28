#include "frame.hpp"
#include "layer.hpp"

using namespace protodoc;
namespace commsdsl::parse
{

void to_json(json_obj &j, const Frame &f)
{
    j.merge_patch({{kKeyFieldName, f.name()}, {kKeyFieldDescription, f.description()}, {kKeyFields, f.layers()}});
}
void to_json(json_obj &j, const Frame::LayersList &f)
{
    for (const auto &layer : f)
        j[layer.name()] = layer;
}

} // namespace commsdsl::parse
