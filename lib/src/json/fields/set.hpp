#pragma once
#include <commsdsl/SetField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::SetField &f);
} // namespace protodoc
