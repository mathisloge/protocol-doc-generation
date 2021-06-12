set(SRCS 
    src/generator.cpp
    src/backend.cpp
    src/backends/asciidoc.cpp
    src/backends/latex.cpp
    src/diagram.cpp
    src/diagrams/ascii.cpp
)
set(HDRS
    include/generator.hpp
    include/backend.hpp
    include/backends/asciidoc.hpp
    include/backends/latex.hpp
    include/diagram.hpp
    include/diagrams/ascii.hpp
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
)
