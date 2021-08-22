#include "namespace.hpp"
#include "../types.hpp"
#include "field.hpp"
#include "frame.hpp"
#include "message.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::Namespace &ns)
{
    if (!ns.description().empty())
        j[kKeyFieldDescription] = ns.description();

    for (const auto &f : ns.frames())
        to_json(j[kKeyFrames][f.name()], f);

    for (const auto &f : ns.fields())
        to_json(j[kKeyFields][f.name()], f);

    for (const auto &m : ns.messages())
        to_json(j[kKeyMessages][m.name()], m);
}
} // namespace protodoc
