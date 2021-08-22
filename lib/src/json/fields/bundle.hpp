#pragma once
#include <commsdsl/BundleField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::BundleField &f);
} // namespace commsdsl
