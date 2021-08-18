#pragma once
#include <commsdsl/Field.h>
#include "def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::Field &f);
} // namespace protodoc
