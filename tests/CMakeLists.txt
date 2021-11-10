find_package(Catch2 REQUIRED)


set(TEST_SCHEMAS 
    src/fields/bitfield.xml

)

add_executable(tests
    src/main.cpp
    src/inja_callbacks.cpp
    src/fields/common.hpp
    src/fields/common.cpp
    src/fields/bitfield.cpp
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
    LIBRARY_OUTPUT_DIRECTORY "${m_output_dir}"
    RUNTIME_OUTPUT_DIRECTORY "${m_output_dir}"
    ARCHIVE_OUTPUT_DIRECTORY "${m_output_dir}"
)

file(COPY ${TEST_SCHEMAS} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

include(Catch)
catch_discover_tests(tests)
