#pragma once
#include <commsdsl/parse/StringField.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const StringField &f);
} // namespace commsdsl::parse
