#pragma once
#include <commsdsl/Units.h>
namespace protodoc
{
constexpr const char *UnitsToString(commsdsl::Units unit)
{
    switch (unit)
    {
        // clang-format off
            case commsdsl::Units::Unknown: return "Unknown";
            // Time
            case commsdsl::Units::Nanoseconds: return "Nanoseconds";
            case commsdsl::Units::Microseconds: return "Microseconds";
            case commsdsl::Units::Milliseconds: return "Milliseconds";
            case commsdsl::Units::Seconds: return "Seconds";
            case commsdsl::Units::Minutes: return "Minutes";
            case commsdsl::Units::Hours: return "Hours";
            case commsdsl::Units::Days: return "Days";
            case commsdsl::Units::Weeks: return "Weeks";
            // Distance  
            case commsdsl::Units::Nanometers: return "Nanometers";
            case commsdsl::Units::Micrometers: return "Micrometers";
            case commsdsl::Units::Millimeters: return "Millimeters";
            case commsdsl::Units::Centimeters: return "Centimeters";
            case commsdsl::Units::Meters: return "Meters";
            case commsdsl::Units::Kilometers: return "Kilometers";
            // Speed
            case commsdsl::Units::NanometersPerSecond: return "NanometersPerSecond";
            case commsdsl::Units::MicrometersPerSecond: return "MicrometersPerSecond";
            case commsdsl::Units::MillimetersPerSecond: return "MillimetersPerSecond";
            case commsdsl::Units::CentimetersPerSecond: return "CentimetersPerSecond";
            case commsdsl::Units::MetersPerSecond: return "MetersPerSecond";
            case commsdsl::Units::KilometersPerSecond: return "KilometersPerSecond";
            case commsdsl::Units::KilometersPerHour: return "KilometersPerHour";
            // Frequency
            case commsdsl::Units::Hertz: return "Hertz";
            case commsdsl::Units::KiloHertz: return "KiloHertz";
            case commsdsl::Units::MegaHertz: return "MegaHertz";
            case commsdsl::Units::GigaHertz: return "GigaHertz";
            // Angle
            case commsdsl::Units::Degrees: return "Degrees";
            case commsdsl::Units::Radians: return "Radians";
            // Electric Current
            case commsdsl::Units::Nanoamps: return "Nanoamps";
            case commsdsl::Units::Microamps: return "Microamps";
            case commsdsl::Units::Milliamps: return "Milliamps";
            case commsdsl::Units::Amps: return "Amps";
            case commsdsl::Units::Kiloamps: return "Kiloamps";
            // Electric Voltage
            case commsdsl::Units::Nanovolts: return "Nanovolts";
            case commsdsl::Units::Microvolts: return "Microvolts";
            case commsdsl::Units::Millivolts: return "Millivolts";
            case commsdsl::Units::Volts: return "Volts";
            case commsdsl::Units::Kilovolts: return "Kilovolts";
            // Memory Size
            case commsdsl::Units::Bytes: return "Bytes";
            case commsdsl::Units::Kilobytes: return "Kilobytes";
            case commsdsl::Units::Megabytes: return "Megabytes";
            case commsdsl::Units::Gigabytes: return "Gigabytes";
            case commsdsl::Units::Terabytes: return "Terabytes";
            default: return "err";
        // clang-format on
    }
}
} // namespace protodoc
