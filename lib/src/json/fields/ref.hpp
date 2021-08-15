#pragma once
#include <commsdsl/RefField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::RefField &f);
} // namespace protodoc
