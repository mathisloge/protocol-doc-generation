#pragma once
#include <commsdsl/parse/Field.h>
#include "../def.hpp"

namespace commsdsl::parse
{
NLOHMANN_JSON_SERIALIZE_ENUM(Field::Kind,
                             {{Field::Kind::Int, "int"},
                              {Field::Kind::Enum, "enum"},
                              {Field::Kind::Set, "set"},
                              {Field::Kind::Float, "float"},
                              {Field::Kind::Bitfield, "bitfield"},
                              {Field::Kind::Bundle, "bundle"},
                              {Field::Kind::String, "string"},
                              {Field::Kind::Data, "data"},
                              {Field::Kind::List, "list"},
                              {Field::Kind::Ref, "ref"},
                              {Field::Kind::Optional, "optional"},
                              {Field::Kind::Variant, "variant"},
                              {Field::Kind::NumOfValues, protodoc::keyValueUnknown}});

NLOHMANN_JSON_SERIALIZE_ENUM(Field::SemanticType,
                             {{Field::SemanticType::None, "none"},
                              {Field::SemanticType::Version, "version"},
                              {Field::SemanticType::MessageId, "msgId"},
                              {Field::SemanticType::Length, "length"},
                              {Field::SemanticType::NumOfValues, protodoc::keyValueUnknown}});

void to_json(protodoc::json_obj &j, const Field &f);
} // namespace commsdsl::parse

namespace protodoc
{
void generateFieldSchema(const std::string &base_url);
}
