#pragma once
#include <commsdsl/Layer.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::Layer &f);
} // namespace protodoc
