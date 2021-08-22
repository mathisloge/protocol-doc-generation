#pragma once
#include <commsdsl/BitfieldField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::BitfieldField &f);
} // namespace commsdsl
