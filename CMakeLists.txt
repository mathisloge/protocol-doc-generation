cmake_minimum_required(VERSION 3.20)
project(protodoc)


find_package(LibCommsdsl CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_subdirectory(lib)
add_subdirectory(app)
