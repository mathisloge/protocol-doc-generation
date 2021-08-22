#pragma once
#include <commsdsl/RefField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::RefField &f);
} // namespace protodoc
