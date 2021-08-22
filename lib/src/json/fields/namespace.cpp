#include "namespace.hpp"
#include "../types.hpp"
#include "field.hpp"
#include "frame.hpp"
#include "message.hpp"

using namespace protodoc;
namespace commsdsl
{
static void to_json(protodoc::json_obj &j, const commsdsl::Namespace::FramesList &frames)
{
    for (const auto &f : frames)
        j[f.name()].merge_patch(f);
}
static void to_json(protodoc::json_obj &j, const commsdsl::Namespace::FieldsList &fields)
{
    for (const auto &f : fields)
        j[f.name()].merge_patch(f);
}
static void to_json(protodoc::json_obj &j, const commsdsl::Namespace::MessagesList &messages)
{
    for (const auto &m : messages)
        j[m.name()].merge_patch(m);
}
void to_json(protodoc::json_obj &j, const commsdsl::Namespace &ns)
{
    j.merge_patch({{kKeyFieldDescription, ns.description()},
                   {kKeyFrames, ns.frames()},
                   {kKeyFields, ns.fields()},
                   {kKeyMessages, ns.messages()}});
}
} // namespace commsdsl
