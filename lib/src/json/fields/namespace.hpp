#pragma once
#include <commsdsl/Namespace.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::Namespace &ns);
} // namespace protodoc
