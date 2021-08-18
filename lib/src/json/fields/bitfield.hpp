#pragma once
#include <commsdsl/BitfieldField.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::BitfieldField &f);
} // namespace protodoc
