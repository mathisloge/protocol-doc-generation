cmake_minimum_required(VERSION 3.21)
set(VCPKG_OVERLAY_PORTS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg-ports/commsdsl")
file(READ vcpkg.json VCPKG_MANIFEST_STR)
string(JSON VCPKG_PROJ_VERSION GET ${VCPKG_MANIFEST_STR} "version-semver")
project(protodoc 
    VERSION ${VCPKG_PROJ_VERSION}
    HOMEPAGE_URL "https://github.com/mathisloge/protocol-doc-generation" 
    LANGUAGES CXX
)
include(GNUInstallDirs)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

include(CTest)
option(BUILD_SHARED_LIBS "build libprotodoc static(OFF) or shared(ON) tests" ON)

if(BUILD_TESTING AND BUILD_SHARED_LIBS) 
    message(WARNING "We need to build static when using the tests")
    set(BUILD_SHARED_LIBS OFF)
endif()

set(m_output_dir "${CMAKE_CURRENT_BINARY_DIR}/out")
find_package(LibXml2 CONFIG REQUIRED) # needed for LibCommsdsl
find_package(LibCommsdsl CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(inja CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(cpp-json-schema CONFIG REQUIRED)

include(GNUInstallDirs)
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_REF)
message(STATUS "GIT_REF: ${GIT_REF}")
message(STATUS "GIT_REFSPEC: ${GIT_REFSPEC}")


add_subdirectory(lib)
add_subdirectory(app)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()


include(install)
include(pack)
