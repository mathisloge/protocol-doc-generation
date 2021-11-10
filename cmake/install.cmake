include(CMakePackageConfigHelpers)
include(third-party-licenses)

install(TARGETS protodoc libprotodoc
    EXPORT protodocTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
string(CONFIGURE [[
file(GET_RUNTIME_DEPENDENCIES
    LIBRARIES $<TARGET_FILE:protodoc>
    EXECUTABLES $<TARGET_FILE:protodoc>
    RESOLVED_DEPENDENCIES_VAR _r_deps
    UNRESOLVED_DEPENDENCIES_VAR _u_deps
    DIRECTORIES 
        "@VCPKG_INSTALLED_DIR@/@VCPKG_TARGET_TRIPLET@/$<$<CONFIG:Debug>:debug/>bin"
    POST_EXCLUDE_REGEXES
        ".*system32/.*\\.dll"
)
foreach(_file IN LISTS _r_deps)
    message("install ${_file} to ${CMAKE_INSTALL_PREFIX}/@CMAKE_INSTALL_BINDIR@")
    file(INSTALL
        DESTINATION "${CMAKE_INSTALL_PREFIX}/@CMAKE_INSTALL_BINDIR@"
        TYPE SHARED_LIBRARY
        FOLLOW_SYMLINK_CHAIN
        FILES "${_file}"
    )
endforeach()
list(LENGTH _u_deps _u_length)
if("${_u_length}" GREATER 0)
    message("Unresolved dependencies detected!: ${_u_deps}")
endif()
]] m_runtime_deps @ONLY)
install(CODE "${m_runtime_deps}")


install(EXPORT protodocTargets
    FILE protodocTargets.cmake
    NAMESPACE protodoc::
    DESTINATION "${PROTODOC_CMAKE_MODULE_INSTALL_DIR}"
)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/protodocConfig.cmake"
    INSTALL_DESTINATION "${PROTODOC_CMAKE_MODULE_INSTALL_DIR}"
    PATH_VARS CMAKE_INSTALL_INCLUDEDIR PROTODOC_CMAKE_MODULE_INSTALL_DIR
)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/protodocConfigVersion.cmake"
    VERSION "${CMAKE_PROJECT_VERSION}"
    COMPATIBILITY SameMajorVersion
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/protodocConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/protodocConfigVersion.cmake"
    DESTINATION "${PROTODOC_CMAKE_MODULE_INSTALL_DIR}"
)

install(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/protodoc_generate.cmake"
    DESTINATION "${PROTODOC_CMAKE_MODULE_INSTALL_DIR}/modules"
)
