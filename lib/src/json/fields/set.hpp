#pragma once
#include <commsdsl/SetField.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::SetField &f);
} // namespace protodoc
