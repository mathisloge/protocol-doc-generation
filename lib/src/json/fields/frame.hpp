#pragma once
#include <commsdsl/Frame.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::Frame &f);
void to_json(protodoc::json_obj &j, const commsdsl::Frame::LayersList &f);
} // namespace commsdsl
