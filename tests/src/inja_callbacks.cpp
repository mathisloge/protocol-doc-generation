#include "inja_callbacks.hpp"
#include <iostream>
#include <catch.hpp>

TEST_CASE("Text gets converted to correct latex text", "[latexText]")
{
    inja::json json = "see line \\texttt{my_file_path}:554";
    inja::Arguments args{&json};
    REQUIRE(protodoc::callbacks::latexText(args) == "see line \\texttt{my\\_file\\_path}:554");
}
