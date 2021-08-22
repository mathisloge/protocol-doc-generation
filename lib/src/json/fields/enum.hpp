#pragma once
#include <commsdsl/EnumField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::EnumField &f);
} // namespace protodoc
