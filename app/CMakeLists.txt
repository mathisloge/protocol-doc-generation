find_package(cxxopts CONFIG REQUIRED)

add_executable(protodoc
    src/main.cpp
    src/options.hpp
    src/options.cpp
)
set_property(TARGET protodoc PROPERTY CXX_STANDARD 20)
target_include_directories(protodoc PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(protodoc PRIVATE 
    protodoc::libprotodoc
    commsdsl::commsdsl
    cxxopts::cxxopts
    spdlog::spdlog
)

configure_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/version.hpp.in" 
    "${CMAKE_CURRENT_BINARY_DIR}/version.hpp"
)
