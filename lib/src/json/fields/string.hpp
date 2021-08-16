#pragma once
#include <commsdsl/StringField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::StringField &f);
} // namespace protodoc
