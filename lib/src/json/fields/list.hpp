#pragma once
#include <commsdsl/ListField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::ListField &f);
} // namespace commsdsl
