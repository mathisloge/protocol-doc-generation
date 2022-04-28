#pragma once
#include <commsdsl/parse/SetField.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const SetField &f);
} // namespace commsdsl::parse
