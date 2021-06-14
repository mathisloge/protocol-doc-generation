#pragma once
#include <commsdsl/IntField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::IntField &f);
} // namespace protodoc
