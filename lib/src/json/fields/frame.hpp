#pragma once
#include <commsdsl/Frame.h>
#include "../def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::Frame &f);
void to_json(json_obj &j, const commsdsl::Frame::LayersList &f);
} // namespace protodoc
