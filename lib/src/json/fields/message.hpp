#pragma once
#include <commsdsl/parse/Message.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const Message &message);
} // namespace commsdsl::parse
