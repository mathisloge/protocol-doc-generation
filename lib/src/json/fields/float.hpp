#pragma once
#include <commsdsl/FloatField.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::FloatField &f);
} // namespace protodoc
