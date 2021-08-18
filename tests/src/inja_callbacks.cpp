#include "inja_callbacks.hpp"
#include <iostream>
#include <catch.hpp>

TEST_CASE("Text gets converted to correct latex text", "[latexText]")
{
    inja::json json = "see line \\texttt{my_file_path}:554";
    inja::Arguments args{&json};
    REQUIRE(protodoc::callbacks::latexText(args) == "see line \\texttt{my\\_file\\_path}:554");
}

TEST_CASE("Sort enum and return a array of the sorted keys by value", "[sortEnum]")
{
    inja::json sort_arg = "value";
    inja::json enum_list;
    enum_list["a"] = {{"value", 100}};
    enum_list["b"] = {{"value", 99}};
    enum_list["c"] = {{"value", 101}};
    enum_list["d"] = {{"value", 98}};
    inja::Arguments args{&enum_list, &sort_arg};
    const inja::json correct_list{"d", "b", "a", "c"};
    REQUIRE(protodoc::callbacks::sortEnum(args) == correct_list);
}
