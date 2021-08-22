#include "common.hpp"
#include <catch.hpp>
#include <json/fields/field.hpp>
#include <json/types.hpp>

namespace protodoc::tests
{
void testCommonFields(const protodoc::json_obj &j, const std::string_view field_type, commsdsl::Field::Kind kind)
{
    REQUIRE_NOTHROW(j.at(kKeyType));
    REQUIRE(j.at(kKeyType).is_string());
    REQUIRE(j.at(kKeyType).get<std::string>() == field_type);

    REQUIRE_NOTHROW(j.at(kKeyFieldKind));
    REQUIRE(j.at(kKeyFieldKind).is_number());
    REQUIRE(j.at(kKeyFieldKind).get<int>() == static_cast<int>(kind));

    REQUIRE_NOTHROW(j.at(kKeyFieldDisplayName));
    REQUIRE(j.at(kKeyFieldDisplayName).is_string());

    REQUIRE_NOTHROW(j.at(kKeyFieldDescription));
    REQUIRE(j.at(kKeyFieldDescription).is_string());
}
} // namespace protodoc::tests
