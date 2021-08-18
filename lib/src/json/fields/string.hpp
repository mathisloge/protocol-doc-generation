#pragma once
#include <commsdsl/StringField.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::StringField &f);
} // namespace protodoc
