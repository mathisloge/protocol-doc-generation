#pragma once
#include <commsdsl/parse/Layer.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const Layer &f);
} // namespace commsdsl::parse
