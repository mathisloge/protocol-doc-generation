#pragma once
#include <commsdsl/FloatField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::FloatField &f);
} // namespace protodoc
