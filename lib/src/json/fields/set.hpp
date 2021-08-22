#pragma once
#include <commsdsl/SetField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::SetField &f);
} // namespace protodoc
