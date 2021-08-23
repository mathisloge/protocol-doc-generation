#pragma once
#include <filesystem>
#include <string>
#include <nlohmann/json.hpp>

namespace protodoc
{
using schema_json = nlohmann::ordered_json;

enum class JsonSchemaType
{};

class JsonSchemaProperty
{
  protected:
    static constexpr const char *kKeyType = "type";
    static constexpr const char *kKeyDescription = "description";

  public:
    JsonSchemaProperty(schema_json &json);
    JsonSchemaProperty(const JsonSchemaProperty &self);
    ~JsonSchemaProperty();

  protected:
    schema_json &schema_;
};

class JsonSchemaBooleanProperty : public JsonSchemaProperty
{
  private:
    static constexpr const char *kType = "boolean";

  public:
    using JsonSchemaProperty::JsonSchemaProperty;
    static const char *Type()
    {
        return kType;
    }
};
class JsonSchemaNullProperty : public JsonSchemaProperty
{
  private:
    static constexpr const char *kType = "null";

  public:
    using JsonSchemaProperty::JsonSchemaProperty;
    static const char *Type()
    {
        return kType;
    }
};

class JsonSchemaEnumProperty : public JsonSchemaProperty
{
  private:
    static constexpr const char *kType = "enum";

  public:
    using JsonSchemaProperty::JsonSchemaProperty;

    JsonSchemaEnumProperty &addValue(const std::string &value_type)
    {
        schema_[kType].emplace_back(value_type);
        return *this;
    }

    static schema_json Type()
    {
        return schema_json{{kType, schema_json::array()}};
    }
};

class JsonSchemaObjectProperty : public JsonSchemaProperty
{
  private:
    static constexpr const char *kKeyProperties = "properties";
    static constexpr const char *kKeyRequired = "required";
    static constexpr const char *kType = "object";

  public:
    using JsonSchemaProperty::JsonSchemaProperty;

    template <typename T>
    T addProperty(const std::string &name, const std::string &description, bool required)
    {
        auto prop = nlohmann::json::object();
        prop[kKeyType] = T::Type();
        if (!description.empty())
            prop[kKeyDescription] = description;
        if (required)
            schema_[kKeyRequired].emplace_back(name);

        schema_[kKeyProperties][name] = std::move(prop);
        return T{schema_[kKeyProperties][name]};
    }

    JsonSchemaObjectProperty &init()
    {
        schema_[kKeyType] = Type();
        return *this;
    }

    static const char *Type()
    {
        return kType;
    }
};

class JsonSchemaNumberProperty : public JsonSchemaProperty
{
  private:
    static constexpr const char *kType = "number";
    static constexpr const char *kKeyMultipleOf = "multipleOf";
    static constexpr const char *kKeyMinimum = "minimum";
    static constexpr const char *kKeyExclusiveMinimum = "exclusiveMinimum";
    static constexpr const char *kKeyMaximum = "maximum";
    static constexpr const char *kKeyExclusiveMaximum = "exclusiveMaximum";

  public:
    using JsonSchemaProperty::JsonSchemaProperty;
    JsonSchemaNumberProperty &setMultipleOf(unsigned int value)
    {
        schema_[kKeyMultipleOf] = value;
        return *this;
    }
    JsonSchemaNumberProperty &setMinimum(int value)
    {
        schema_[kKeyMinimum] = value;
        return *this;
    }
    JsonSchemaNumberProperty &setExclusiveMinimum(int value)
    {
        schema_[kKeyExclusiveMinimum] = value;
        return *this;
    }
    JsonSchemaNumberProperty &setMaximum(int value)
    {
        schema_[kKeyMaximum] = value;
        return *this;
    }
    JsonSchemaNumberProperty &setExclusiveMaximum(int value)
    {
        schema_[kKeyExclusiveMaximum] = value;
        return *this;
    }

    static const char *Type()
    {
        return kType;
    }
};

class JsonSchemaIntegerProperty : public JsonSchemaNumberProperty
{
  private:
    static constexpr const char *kType = "integer";

  public:
    using JsonSchemaNumberProperty::JsonSchemaNumberProperty;

    static const char *Type()
    {
        return kType;
    }
};

class JsonSchemaArrayProperty : public JsonSchemaProperty
{
  private:
    static constexpr const char *kType = "array";
    static constexpr const char *kKeyItems = "items";
    static constexpr const char *kKeyItemType = "type";
    static constexpr const char *kKeyUniqueItems = "uniqueItems";

  public:
    using JsonSchemaProperty::JsonSchemaProperty;

    template <typename T>
    T setItemType()
    {
        schema_[kKeyItems][kKeyItemType] = T::Type();
        return T{schema_[kKeyItems][kKeyItemType]};
    }
    JsonSchemaArrayProperty setUniqueItems(bool is_unique)
    {
        schema_[kKeyUniqueItems] = is_unique;
        return *this;
    }

    static const char *Type()
    {
        return kType;
    }
};

class JsonSchemaRefProperty : public JsonSchemaProperty
{
  public:
    JsonSchemaRefProperty &setRef(const std::string &url);
};

class JsonSchema final : public JsonSchemaProperty
{
  public:
    explicit JsonSchema(const std::string &schema_name);
    ~JsonSchema();
    void write(const std::filesystem::path &output_dir);

    JsonSchema &setTitle(const std::string &title);
    JsonSchema &setDescription(const std::string &description);

    schema_json &json();

  private:
    const std::string schema_name_;
    schema_json schema_;
};
} // namespace protodoc
