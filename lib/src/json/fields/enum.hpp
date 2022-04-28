#pragma once
#include <commsdsl/parse/EnumField.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const EnumField &f);
} // namespace commsdsl::parse
