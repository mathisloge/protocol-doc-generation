#pragma once
#include <commsdsl/VariantField.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::VariantField &f);
} // namespace protodoc
