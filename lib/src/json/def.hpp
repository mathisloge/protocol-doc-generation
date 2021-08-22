#pragma once
#include <string_view>
#include <nlohmann/json.hpp>
namespace protodoc
{
using json_obj = nlohmann::ordered_json;

static constexpr const char *kKeyPlatforms = "platforms";
static constexpr const char *kKeyNamespace = "namespaces";
static constexpr const char *kKeyFrames = "frames";
static constexpr const char *kKeyMessages = "messages";
static constexpr const char *kKeyFields = "fields";
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
inline constexpr const char *kKeyEndian = "endian";

inline constexpr std::string_view kBitfieldType = "bitfield";
inline constexpr std::string_view kOptionalType = "optional";
inline constexpr std::string_view kDataType = "data";
inline constexpr std::string_view kBundleType = "bundle";
inline constexpr std::string_view kListType = "list";
inline constexpr std::string_view kRefType = "ref";
inline constexpr std::string_view kSetType = "set";
inline constexpr std::string_view kStringType = "string";
inline constexpr std::string_view kVariantType = "variant";

inline constexpr const char *keyValueUnknown = "unknown";

} // namespace protodoc
