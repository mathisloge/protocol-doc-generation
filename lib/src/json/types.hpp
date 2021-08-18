#pragma once
#include <string_view>
#include <commsdsl/FloatField.h>
#include <commsdsl/IntField.h>

namespace protodoc
{

inline constexpr const char *kKeyType = "type";
inline constexpr const char *kKeyFieldName = "name";
inline constexpr const char *kKeyFieldDisplayName = "displayName";
inline constexpr const char *kKeyFieldSemanticType = "semanticType";
inline constexpr const char *kKeyFieldKind = "kind";
inline constexpr const char *kKeyFieldDescription = "description";
inline constexpr const char *kKeyFieldDeprecatedSince = "deprecatedSince";
inline constexpr const char *kKeyFieldSinceVersion = "sinceVersion";
inline constexpr const char *kKeyFieldMinLength = "minLength";
inline constexpr const char *kKeyFieldMaxLength = "maxLength";
inline constexpr const char *kKeyFieldUnits = "units";
inline constexpr const char *kKeyFieldScaling = "scaling";
inline constexpr const char *kKeyFieldRange = "range";
inline constexpr const char *kKeyFieldMembers = "members";
inline constexpr const char *kKeyFieldField = "field";

inline constexpr std::string_view kBitfieldType = "bitfield";
inline constexpr std::string_view kOptionalType = "optional";
inline constexpr std::string_view kDataType = "data";
inline constexpr std::string_view kBundleType = "bundle";
inline constexpr std::string_view kListType = "list";
inline constexpr std::string_view kRefType = "ref";
inline constexpr std::string_view kSetType = "set";
inline constexpr std::string_view kStringType = "string";
inline constexpr std::string_view kVariantType = "variant";

constexpr const char *SemanticTypeToString(commsdsl::Field::SemanticType type)
{
    using Type = commsdsl::Field::SemanticType;
    // clang-format off
    switch (type)
    {
        case Type::None: return "none";
        case Type::Version: return "version";
        case Type::MessageId: return "msgId";
        case Type::Length: return "length";
        default: return "unknown";
    }
    // clang-format on
}

constexpr const char *TypeToString(commsdsl::IntField::Type type)
{
    using Type = commsdsl::IntField::Type;
    // clang-format off
    switch (type)
    {
        case Type::Int8: return "int8";
        case Type::Uint8: return "uint8";
        case Type::Int16: return "int16";
        case Type::Uint16: return "uint16";
        case Type::Int32: return "int32";
        case Type::Uint32: return "uint32";
        case Type::Int64: return "int64";
        case Type::Uint64: return "uint64";
        case Type::Intvar: return "intvar";
        case Type::Uintvar: return "uintvar";
        default: return "unknown";
    }
    // clang-format on
}

constexpr const char *TypeToString(commsdsl::FloatField::Type type)
{
    using Type = commsdsl::FloatField::Type;
    // clang-format off
    switch (type)
    {
        case Type::Float: return "float";
        case Type::Double: return "double";
        default: return "unknown";
    }
    // clang-format on
}
} // namespace protodoc
