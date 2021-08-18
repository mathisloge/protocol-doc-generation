project(libprotodoc)
set(SRCS 
    src/generator.cpp
    src/inja_callbacks.cpp
    src/json/platform.cpp
    src/json/namespace.cpp
    src/json/field.cpp
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
    src/json/frame.cpp
    src/json/layer.cpp
    src/json/message.cpp
)
set(HDRS
    include/generator.hpp
    src/inja_callbacks.hpp
    src/json/endian.hpp
    src/json/json.hpp
    src/json/platform.hpp
    src/json/namespace.hpp
    src/json/field.hpp
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
    src/json/units.hpp
    src/json/types.hpp
    src/json/frame.hpp
    src/json/layer.hpp
    src/json/message.hpp
)

add_library(libprotodoc ${SRCS} ${HDRS})
add_library(protodoc::libprotodoc ALIAS libprotodoc)
set_target_properties(libprotodoc PROPERTIES 
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON 
    CXX_EXTENSIONS OFF
)
target_compile_definitions(libprotodoc PRIVATE INJA_THROW=throw)
target_include_directories(libprotodoc PUBLIC 
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_link_libraries(libprotodoc PRIVATE 
    commsdsl::commsdsl
    spdlog::spdlog
    pantor::inja
)
