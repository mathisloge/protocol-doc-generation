#pragma once
#include <commsdsl/Frame.h>
#include <nlohmann/json.hpp>

namespace protodoc
{
void to_json(nlohmann::json &j, const commsdsl::Frame &f);
void to_json(nlohmann::json &j, const commsdsl::Frame::LayersList &f);
} // namespace protodoc
