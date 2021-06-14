#pragma once
#include <commsdsl/Message.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::Message &message);
} // namespace protodoc
