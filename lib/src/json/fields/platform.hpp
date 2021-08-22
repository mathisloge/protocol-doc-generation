#pragma once
#include <commsdsl/Protocol.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::Protocol::PlatformsList &platforms);
} // namespace protodoc
