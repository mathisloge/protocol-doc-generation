#pragma once
#include <commsdsl/RefField.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::RefField &f);
} // namespace protodoc
