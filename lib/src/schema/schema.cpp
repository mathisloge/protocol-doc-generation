#include "schema.hpp"
#include <fstream>
namespace protodoc
{

JsonSchemaProperty::JsonSchemaProperty(schema_json &json)
    : schema_{json}
{}
JsonSchemaProperty::JsonSchemaProperty(const JsonSchemaProperty &self)
    : schema_{self.schema_}
{}
JsonSchemaProperty::~JsonSchemaProperty()
{}

JsonSchema::JsonSchema(const std::string &schema_name)
    : JsonSchemaProperty{schema_}
    , schema_name_{schema_name}
{
    schema_["$ref"] = "https://json-schema.org/draft/2020-12/schema";
}
JsonSchema::~JsonSchema()
{}
void JsonSchema::write(const std::filesystem::path &output_dir)
{
    std::ofstream file{output_dir / schema_name_};
    file << std::setw(4) << schema_ << std::endl;
}

JsonSchema &JsonSchema::setTitle(const std::string &title)
{
    schema_["title"] = title;
    return *this;
}
JsonSchema &JsonSchema::setDescription(const std::string &description)
{
    schema_["description"] = description;
    return *this;
}

schema_json &JsonSchema::json()
{
    return schema_;
}

} // namespace protodoc
