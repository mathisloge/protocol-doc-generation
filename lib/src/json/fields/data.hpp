#pragma once
#include <commsdsl/DataField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::DataField &f);
} // namespace protodoc
