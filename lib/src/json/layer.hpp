#pragma once
#include <commsdsl/Layer.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::Layer &f);
} // namespace protodoc
