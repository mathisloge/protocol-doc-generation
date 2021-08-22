project(libprotodoc)
include(GenerateExportHeader)
set(SRCS 
    src/generator.cpp
    src/inja_callbacks.cpp
    src/json/fields/platform.cpp
    src/json/fields/namespace.cpp
    src/json/fields/field.cpp
    src/json/fields/bitfield.cpp
    src/json/fields/enum.cpp
    src/json/fields/float.cpp
    src/json/fields/int.cpp
    src/json/fields/optional.cpp
    src/json/fields/ref.cpp
    src/json/fields/data.cpp
    src/json/fields/bundle.cpp
    src/json/fields/list.cpp
    src/json/fields/set.cpp
    src/json/fields/string.cpp
    src/json/fields/variant.cpp
    src/json/fields/frame.cpp
    src/json/fields/layer.cpp
    src/json/fields/message.cpp
)
set(HDRS
    include/protodoc/generator.hpp
    src/inja_callbacks.hpp
    src/json/endian.hpp
    src/json/units.hpp
    src/json/types.hpp
    src/json/json.hpp
    src/json/fields/field.hpp
    src/json/fields/platform.hpp
    src/json/fields/namespace.hpp
    src/json/fields/bitfield.hpp
    src/json/fields/enum.hpp
    src/json/fields/float.hpp
    src/json/fields/int.hpp
    src/json/fields/optional.hpp
    src/json/fields/ref.hpp
    src/json/fields/data.hpp
    src/json/fields/bundle.hpp
    src/json/fields/list.hpp
    src/json/fields/set.hpp
    src/json/fields/string.hpp
    src/json/fields/variant.hpp
    src/json/fields/frame.hpp
    src/json/fields/layer.hpp
    src/json/fields/message.hpp
)

add_library(libprotodoc ${SRCS} ${HDRS})
add_library(protodoc::libprotodoc ALIAS libprotodoc)
generate_export_header(libprotodoc BASE_NAME protodoc EXPORT_FILE_NAME "protodoc_export.hpp")
set_target_properties(libprotodoc PROPERTIES 
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON 
    CXX_EXTENSIONS OFF
    OUTPUT_NAME "protodoc"
    DEBUG_POSTFIX "d" 
    PREFIX "lib"
)
target_compile_definitions(libprotodoc PRIVATE INJA_THROW=throw)
target_include_directories(libprotodoc PUBLIC 
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)
target_link_libraries(libprotodoc PUBLIC 
    commsdsl::commsdsl
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    pantor::inja
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/protodoc_export.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
