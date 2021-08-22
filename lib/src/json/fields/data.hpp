#pragma once
#include <commsdsl/DataField.h>
#include "../def.hpp"

using namespace protodoc;
namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::DataField &f);
} // namespace protodoc
