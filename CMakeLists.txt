cmake_minimum_required(VERSION 3.21)
project(protodoc VERSION 1.0.0)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

option(BUILD_TESTING "build the tests" ON)

find_package(LibCommsdsl CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(inja CONFIG REQUIRED)

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
