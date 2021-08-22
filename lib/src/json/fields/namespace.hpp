#pragma once
#include <commsdsl/Namespace.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::Namespace &ns);
} // namespace protodoc
