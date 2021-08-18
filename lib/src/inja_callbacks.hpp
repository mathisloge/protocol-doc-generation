#pragma once
#include <string>
#include <inja/inja.hpp>
namespace protodoc::callbacks
{
inja::json latexText(inja::Arguments &args);
inja::json sortEnum(inja::Arguments &args);
} // namespace protodoc::callbacks
