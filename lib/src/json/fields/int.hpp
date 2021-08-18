#pragma once
#include <commsdsl/IntField.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::IntField &f);
} // namespace protodoc
