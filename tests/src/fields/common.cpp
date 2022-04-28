#include "common.hpp"
#include <catch.hpp>
#include <json/fields/field.hpp>
namespace protodoc::tests
{
void testCommonFields(const protodoc::json_obj &j, commsdsl::parse::Field::Kind kind, commsdsl::parse::Field::SemanticType semantic)
{
    REQUIRE_NOTHROW(j.at(kKeyFieldSemanticType));
    REQUIRE(j.at(kKeyFieldSemanticType).is_string());
    REQUIRE(j.at(kKeyFieldSemanticType).get<commsdsl::parse::Field::SemanticType>() == semantic);

    REQUIRE_NOTHROW(j.at(kKeyFieldKind));
    REQUIRE(j.at(kKeyFieldKind).is_string());
    REQUIRE(j.at(kKeyFieldKind).get<commsdsl::parse::Field::Kind>() == kind);

    REQUIRE_NOTHROW(j.at(kKeyFieldName));
    REQUIRE(j.at(kKeyFieldName).is_string());

    REQUIRE_NOTHROW(j.at(kKeyFieldDisplayName));
    REQUIRE(j.at(kKeyFieldDisplayName).is_string());

    REQUIRE_NOTHROW(j.at(kKeyFieldDescription));
    REQUIRE(j.at(kKeyFieldDescription).is_string());
}
} // namespace protodoc::tests
