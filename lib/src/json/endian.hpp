#pragma once
#include <commsdsl/Endian.h>

namespace protodoc
{
constexpr const char *EndianToString(commsdsl::Endian type)
{
    using Endian = commsdsl::Endian;
    // clang-format off
    switch (type)
    {
    case Endian::Endian_Little: return "endian_little";
    case Endian::Endian_Big: return "endian_big";
    default: return "unknown";
    }
    // clang-format on
}
} // namespace protodoc