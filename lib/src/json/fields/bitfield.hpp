#pragma once
#include <commsdsl/BitfieldField.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::BitfieldField &f);
} // namespace protodoc
