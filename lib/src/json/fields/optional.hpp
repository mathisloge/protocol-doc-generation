#pragma once
#include <commsdsl/OptionalField.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::OptionalField &f);
} // namespace protodoc
