#pragma once
#include <commsdsl/EnumField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::EnumField &f);
} // namespace protodoc
