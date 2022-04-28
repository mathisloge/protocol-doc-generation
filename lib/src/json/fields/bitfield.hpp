#pragma once
#include <commsdsl/parse/BitfieldField.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const BitfieldField &f);
} // namespace commsdsl::parse
