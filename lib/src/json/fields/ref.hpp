#pragma once
#include <commsdsl/parse/RefField.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const RefField &f);
} // namespace commsdsl::parse
