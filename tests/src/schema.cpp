#include "schema/schema.hpp"
#include <catch.hpp>
#include "json/fields/field.hpp"
#include "json/fields/int.hpp"

using namespace protodoc;

static constexpr const char* kBaseUrl = "";
TEST_CASE("Schema generation", "[schema]")
{
    JsonSchema schema{kBaseUrl, "test_schema.json"};
    schema.setTitle("TestSchema").setDescription("TestDescription");

    JsonSchemaObjectProperty p(schema.json());
    p.init();
    auto testobj{p.addProperty<JsonSchemaObjectProperty>("TestObj1", "", true)};
    testobj.addProperty<JsonSchemaNullProperty>("nulltest", "this is a null value", false);

    schema.write(std::filesystem::current_path());
}


TEST_CASE("schema field example", "[schmema]")
{
    generateFieldSchema(kBaseUrl);
    generateIntFieldSchema(kBaseUrl);
}
