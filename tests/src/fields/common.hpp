#pragma once
#include <string_view>
#include <commsdsl/Field.h>
#include <json/def.hpp>

namespace protodoc::tests
{
void testCommonFields(const protodoc::json_obj &j, commsdsl::Field::Kind kind, commsdsl::Field::SemanticType semantic);
}
