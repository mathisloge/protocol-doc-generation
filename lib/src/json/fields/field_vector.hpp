#pragma once
#include <vector>
#include <commsdsl/parse/Field.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const std::vector<Field> &fields);
}
