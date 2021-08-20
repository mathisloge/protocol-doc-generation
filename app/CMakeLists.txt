find_package(cxxopts CONFIG REQUIRED)

add_executable(protodoc
    src/main.cpp
    src/options.hpp
    src/options.cpp
)

set_property(TARGET protodoc PROPERTY CXX_STANDARD 20)

target_link_libraries(protodoc PRIVATE 
    protodoc::libprotodoc
    commsdsl::commsdsl
    cxxopts::cxxopts
    spdlog::spdlog
)
