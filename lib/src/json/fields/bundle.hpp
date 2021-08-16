#pragma once
#include <commsdsl/BundleField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::BundleField &f);
} // namespace protodoc
