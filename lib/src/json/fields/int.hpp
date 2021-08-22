#pragma once
#include <commsdsl/IntField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::IntField &f);
} // namespace protodoc
