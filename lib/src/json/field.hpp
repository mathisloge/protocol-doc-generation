#pragma once
#include <commsdsl/Field.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::Field &f);
} // namespace protodoc
