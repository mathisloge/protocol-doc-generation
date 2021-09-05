#pragma once
#include <commsdsl/IntField.h>
#include "../def.hpp"

namespace commsdsl
{
void to_json(protodoc::json_obj &j, const commsdsl::IntField &f);
} // namespace commsdsl
namespace protodoc
{
void generateIntFieldSchema(const std::string& base_url);
}
