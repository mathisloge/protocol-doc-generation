#pragma once
#include <commsdsl/FloatField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::FloatField &f);
} // namespace commsdsl
