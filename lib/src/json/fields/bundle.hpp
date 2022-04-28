#pragma once
#include <commsdsl/parse/BundleField.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const BundleField &f);
} // namespace commsdsl::parse
