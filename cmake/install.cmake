include(CMakePackageConfigHelpers)
include(third-party-licenses)

install(TARGETS protodoc libprotodoc
    EXPORT protodocTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(EXPORT protodocTargets
    FILE protodocTargets.cmake
    NAMESPACE protodoc::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/protodoc
)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/protodocConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/protodoc
)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/protodocConfigVersion.cmake"
    VERSION "${CMAKE_PROJECT_VERSION}"
    COMPATIBILITY SameMajorVersion
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/protodocConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/protodocConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/protodoc
)
