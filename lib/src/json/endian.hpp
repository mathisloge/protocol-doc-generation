#pragma once
#include <commsdsl/Endian.h>
#include "def.hpp"

namespace commsdsl
{
NLOHMANN_JSON_SERIALIZE_ENUM(Endian,
                             {{Endian::Endian_Little, "littleEndian"},
                              {Endian::Endian_Big, "bigEndian"},
                              {Endian::Endian_NumOfValues, protodoc::keyValueUnknown}});
} // namespace commsdsl
