set(SRCS 
    src/generator.cpp
    src/diagram.cpp
    src/diagrams/ascii.cpp
    src/json/platform.cpp
    src/json/field.cpp
    src/json/fields/bitfield.cpp
    src/json/fields/enum.cpp
    src/json/fields/float.cpp
    src/json/fields/int.cpp
    src/json/frame.cpp
    src/json/layer.cpp
    src/json/message.cpp
)
set(HDRS
    include/generator.hpp
    include/diagram.hpp
    include/diagrams/ascii.hpp
    src/json/endian.hpp
    src/json/json.hpp
    src/json/platform.hpp
    src/json/field.hpp
    src/json/fields/bitfield.hpp
    src/json/fields/enum.hpp
    src/json/fields/float.hpp
    src/json/fields/int.hpp
    src/json/units.hpp
    src/json/types.hpp
    src/json/frame.hpp
    src/json/layer.hpp
    src/json/message.hpp
)

add_library(protodoc
    ${SRCS}
    ${HDRS}
)
add_library(protodoc::protodoc ALIAS protodoc)

target_include_directories(protodoc PUBLIC 
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

set_property(TARGET protodoc PROPERTY CXX_STANDARD 20)
target_link_libraries(protodoc PRIVATE 
    commsdsl::commsdsl
    spdlog::spdlog
    pantor::inja
)
target_compile_definitions(protodoc PRIVATE -DINJA_THROW=throw)
