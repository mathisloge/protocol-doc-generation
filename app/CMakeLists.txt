find_package(cxxopts CONFIG REQUIRED)

add_executable(protodoc
    src/main.cpp
    src/options.hpp
    src/options.cpp
)
target_include_directories(protodoc PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(protodoc PRIVATE 
    protodoc::libprotodoc
    commsdsl::commsdsl
    cxxopts::cxxopts
    spdlog::spdlog
)
set_target_properties(protodoc PROPERTIES 
    CXX_EXTENSIONS OFF
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    LIBRARY_OUTPUT_DIRECTORY "${m_output_dir}"
    RUNTIME_OUTPUT_DIRECTORY "${m_output_dir}"
    ARCHIVE_OUTPUT_DIRECTORY "${m_output_dir}"
)

configure_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/version.hpp.in" 
    "${CMAKE_CURRENT_BINARY_DIR}/version.hpp"
)

add_custom_command(TARGET protodoc POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:protodoc::libprotodoc>" "$<TARGET_FILE_DIR:protodoc>")
