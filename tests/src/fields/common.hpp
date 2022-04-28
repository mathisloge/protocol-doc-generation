#pragma once
#include <string_view>
#include <commsdsl/parse/Field.h>
#include <json/def.hpp>

namespace protodoc::tests
{
void testCommonFields(const protodoc::json_obj &j, commsdsl::parse::Field::Kind kind, commsdsl::parse::Field::SemanticType semantic);
}
