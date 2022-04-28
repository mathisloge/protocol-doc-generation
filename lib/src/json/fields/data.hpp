#pragma once
#include <commsdsl/parse/DataField.h>
#include "../def.hpp"

using namespace protodoc;
namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const DataField &f);
} // namespace commsdsl::parse
