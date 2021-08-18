#pragma once
#include <commsdsl/Protocol.h>
#include "def.hpp"

namespace protodoc
{
void to_json(json_obj &j, const commsdsl::Protocol::PlatformsList &platforms);
} // namespace protodoc
