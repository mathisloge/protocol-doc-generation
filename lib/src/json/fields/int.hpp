#pragma once
#include <commsdsl/parse/IntField.h>
#include "../def.hpp"

namespace commsdsl::parse
{
void to_json(protodoc::json_obj &j, const IntField &f);
} // namespace commsdsl::parse
namespace protodoc
{
void generateIntFieldSchema(const std::string &base_url);
}
