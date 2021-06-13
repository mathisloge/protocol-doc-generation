#pragma once
#include <commsdsl/Protocol.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::Protocol::PlatformsList &platforms);
} // namespace protodoc
