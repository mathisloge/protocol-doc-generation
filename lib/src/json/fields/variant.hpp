#pragma once
#include <commsdsl/VariantField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::VariantField &f);
} // namespace protodoc
