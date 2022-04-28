#pragma once
#include <commsdsl/parse/OptionalField.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const OptionalField &f);
} // namespace commsdsl::parse
