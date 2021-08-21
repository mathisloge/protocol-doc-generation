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

set(PROTODOC_RUNTIME_DIR "bin")
install(TARGETS protodoc RUNTIME DESTINATION ${PROTODOC_RUNTIME_DIR} COMPONENT applications)


install(CODE [[
    file(GET_RUNTIME_DEPENDENCIES
        LIBRARIES $<TARGET_FILE:protodoc>
        EXECUTABLES $<TARGET_FILE:protodoc>
        RESOLVED_DEPENDENCIES_VAR _r_deps
        UNRESOLVED_DEPENDENCIES_VAR _u_deps
        DIRECTORIES ${MY_DEPENDENCY_PATHS}
        POST_EXCLUDE_REGEXES
            ".*system32/.*\\.dll"
    )
    foreach(_file IN LISTS _r_deps)
        file(INSTALL
            DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
            TYPE SHARED_LIBRARY
            FOLLOW_SYMLINK_CHAIN
            FILES "${_file}"
        )
    endforeach()
    list(LENGTH _u_deps _u_length)
    if("${_u_length}" GREATER 0)
        message(WARNING "Unresolved dependencies detected!: ${_u_deps}")
    endif()
]])
