#pragma once
#include <commsdsl/parse/Namespace.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const Namespace &ns);
} // namespace commsdsl::parse
