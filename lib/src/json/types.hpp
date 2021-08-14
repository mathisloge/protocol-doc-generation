#pragma once
#include <string_view>
#include <commsdsl/FloatField.h>
#include <commsdsl/IntField.h>
namespace protodoc
{

inline constexpr std::string_view kBitfieldType = "bitfield";
inline constexpr std::string_view kOptionalType = "optional";

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
