#pragma once
#include <commsdsl/parse/VariantField.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const VariantField &f);
} // namespace commsdsl::parse
