cmake_minimum_required(VERSION 3.21)
project(protodoc VERSION 1.0.0)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

option(BUILD_TESTING "build the tests" ON)

find_package(LibCommsdsl CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(inja CONFIG REQUIRED)

include(GNUInstallDirs)
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_REF)
message(STATUS "GIT_REF: ${GIT_REF}")
message(STATUS "GIT_REFSPEC: ${GIT_REFSPEC}")


add_subdirectory(lib)
add_subdirectory(app)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

include(CMakePackageConfigHelpers)
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

include(pack)
