#pragma once
#include <commsdsl/Message.h>
#include "def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::Message &message);
} // namespace protodoc
