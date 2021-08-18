#pragma once
#include <commsdsl/BundleField.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::BundleField &f);
} // namespace protodoc
