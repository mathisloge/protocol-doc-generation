#pragma once
#include <commsdsl/parse/ListField.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const ListField &f);
} // namespace commsdsl::parse
