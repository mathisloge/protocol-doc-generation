#pragma once
#include <commsdsl/OptionalField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::OptionalField &f);
} // namespace protodoc
