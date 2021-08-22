#pragma once
#include <commsdsl/StringField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::StringField &f);
} // namespace commsdsl
