#pragma once
#include <commsdsl/parse/Protocol.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const Protocol::PlatformsList &platforms);
} // namespace commsdsl::parse
