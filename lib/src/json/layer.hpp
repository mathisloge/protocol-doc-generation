#pragma once
#include <commsdsl/Layer.h>
#include "def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::Layer &f);
} // namespace protodoc
