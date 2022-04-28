#pragma once
#include <commsdsl/parse/FloatField.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const FloatField &f);
} // namespace commsdsl::parse
