#pragma once
#include <commsdsl/ListField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::ListField &f);
} // namespace protodoc
