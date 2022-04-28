#include <iomanip>
#include <iostream>
#include <catch.hpp>
#include <commsdsl/parse/commsdsl.h>
#include <json/def.hpp>
#include <json/fields/field.hpp>
#include "common.hpp"

using namespace protodoc;
TEST_CASE("BitfieldField json structure test", "[fields]")
{
    commsdsl::parse::Protocol p;
    const bool parsed = p.parse("bitfield.xml");
    REQUIRE(parsed);
    REQUIRE(p.validate());
    protodoc::json_obj j = p.findField("Bitfield1");
    tests::testCommonFields(j, commsdsl::parse::Field::Kind::Bitfield, commsdsl::parse::Field::SemanticType::None);
    REQUIRE(j.at(kKeyFieldDisplayName).get<std::string>() == "Proper Bitfield Name");
    REQUIRE(j.at(kKeyFieldDescription).get<std::string>() == "Bitfield description");

    REQUIRE_NOTHROW(j.at("members"));
    const auto &members = j.at("members");
    REQUIRE(members.is_object());
    REQUIRE(members.size() == 3);
    REQUIRE((*members.find("Enum1"))["protodocOrder"] == 0);
    REQUIRE((*members.find("Int1"))["protodocOrder"] == 2);
}
