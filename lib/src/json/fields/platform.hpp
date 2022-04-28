#pragma once
#include <commsdsl/parse/Protocol.h>
#include "../def.hpp"

namespace protodoc
{
void platforms_to_json(protodoc::json_obj &j, const commsdsl::parse::Protocol::PlatformsList &platforms);
} // namespace commsdsl::parse
