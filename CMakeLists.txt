cmake_minimum_required(VERSION 3.21)
project(protodoc)


find_package(LibCommsdsl CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(inja CONFIG REQUIRED)

add_subdirectory(lib)
add_subdirectory(app)
