#pragma once
#include <commsdsl/DataField.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::DataField &f);
} // namespace protodoc
