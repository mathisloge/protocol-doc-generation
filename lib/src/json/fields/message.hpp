#pragma once
#include <commsdsl/Message.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::Message &message);
} // namespace commsdsl
