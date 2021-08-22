#pragma once
#include <commsdsl/Field.h>
#include "def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::Field &f);
} // namespace protodoc
