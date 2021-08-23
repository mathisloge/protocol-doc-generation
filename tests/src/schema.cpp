#include "schema/schema.hpp"
#include <catch.hpp>

using namespace protodoc;

TEST_CASE("Schema generation", "[schema]")
{
    JsonSchema schema{"test_schema.json"};
    schema.setTitle("TestSchema").setDescription("TestDescription");

    JsonSchemaObjectProperty p(schema.json());
    p.init();
    auto testobj{p.addProperty<JsonSchemaObjectProperty>("TestObj1", "", true)};
    testobj.addProperty<JsonSchemaNullProperty>("nulltest", "this is a null value", false);

    schema.write(std::filesystem::current_path());
}
