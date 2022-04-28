#pragma once
#include <commsdsl/parse/Frame.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const Frame &f);
void to_json(protodoc::json_obj &j, const Frame::LayersList &f);
} // namespace commsdsl::parse
