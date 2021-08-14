#pragma once
#include <commsdsl/OptionalField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::OptionalField &f);
} // namespace protodoc
