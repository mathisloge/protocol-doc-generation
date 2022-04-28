#pragma once
#include <commsdsl/parse/Units.h>
#include "def.hpp"
namespace commsdsl::parse
{
NLOHMANN_JSON_SERIALIZE_ENUM(Units,
                             {{Units::Unknown, "unknown"},
                              // Time
                              {Units::Nanoseconds, "nanoseconds"},
                              {Units::Microseconds, "microseconds"},
                              {Units::Milliseconds, "milliseconds"},
                              {Units::Seconds, "seconds"},
                              {Units::Minutes, "minutes"},
                              {Units::Hours, "hours"},
                              {Units::Days, "days"},
                              {Units::Weeks, "weeks"},
                              // Distance
                              {Units::Nanometers, "nanometers"},
                              {Units::Micrometers, "micrometers"},
                              {Units::Millimeters, "millimeters"},
                              {Units::Centimeters, "centimeters"},
                              {Units::Meters, "meters"},
                              {Units::Kilometers, "kilometers"},
                              // Speed
                              {Units::NanometersPerSecond, "nanometersPerSecond"},
                              {Units::MicrometersPerSecond, "micrometersPerSecond"},
                              {Units::MillimetersPerSecond, "millimetersPerSecond"},
                              {Units::CentimetersPerSecond, "centimetersPerSecond"},
                              {Units::MetersPerSecond, "metersPerSecond"},
                              {Units::KilometersPerSecond, "kilometersPerSecond"},
                              {Units::KilometersPerHour, "kilometersPerHour"},
                              // Frequency
                              {Units::Hertz, "hertz"},
                              {Units::KiloHertz, "kiloHertz"},
                              {Units::MegaHertz, "megaHertz"},
                              {Units::GigaHertz, "gigaHertz"},
                              // Angle
                              {Units::Degrees, "degrees"},
                              {Units::Radians, "radians"},
                              // Electric Current
                              {Units::Nanoamps, "nanoamps"},
                              {Units::Microamps, "microamps"},
                              {Units::Milliamps, "milliamps"},
                              {Units::Amps, "amps"},
                              {Units::Kiloamps, "kiloamps"},
                              // Electric Voltage
                              {Units::Nanovolts, "nanovolts"},
                              {Units::Microvolts, "microvolts"},
                              {Units::Millivolts, "millivolts"},
                              {Units::Volts, "volts"},
                              {Units::Kilovolts, "kilovolts"},
                              // Memory Size
                              {Units::Bytes, "bytes"},
                              {Units::Kilobytes, "kilobytes"},
                              {Units::Megabytes, "megabytes"},
                              {Units::Gigabytes, "gigabytes"},
                              {Units::Terabytes, "terabytes"},
                              {Units::NumOfValues, protodoc::keyValueUnknown}});

}
