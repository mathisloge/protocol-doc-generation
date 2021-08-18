find_package(Catch2 REQUIRED)


add_executable(tests
    src/main.cpp
    src/inja_callbacks.cpp
)
target_link_libraries(tests PRIVATE 
    Catch2::Catch2 
    protodoc::libprotodoc
)
target_include_directories(tests PRIVATE "${libprotodoc_SOURCE_DIR}/src")
set_target_properties(tests PROPERTIES 
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON 
    CXX_EXTENSIONS OFF
)

include(Catch)
catch_discover_tests(tests)
