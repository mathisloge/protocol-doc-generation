#pragma once
#include <commsdsl/ListField.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::ListField &f);
} // namespace protodoc
