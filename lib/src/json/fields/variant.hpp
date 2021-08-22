#pragma once
#include <commsdsl/VariantField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::VariantField &f);
} // namespace commsdsl
