cmake_minimum_required(VERSION 3.21)
project(protodoc 
    VERSION 1.0.0 
    HOMEPAGE_URL "https://github.com/mathisloge/protocol-doc-generation" 
    LANGUAGES CXX
)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

option(BUILD_TESTING "build the tests" ON)
option(BUILD_SHARED_LIBS "build libprotodoc static(OFF) or shared(ON) tests" ON)
set(PROTODOC_CMAKE_MODULE_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/protodoc")

if(BUILD_TESTING AND BUILD_SHARED_LIBS) 
    message(WARNING "We need to build static when using the tests")
    set(BUILD_SHARED_LIBS OFF)
endif()

find_package(LibCommsdsl CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(inja CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

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


include(install)
include(pack)
