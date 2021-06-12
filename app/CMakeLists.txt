
add_executable(protodocapp
    src/main.cpp
)

set_property(TARGET protodocapp PROPERTY CXX_STANDARD 20)

target_link_libraries(protodocapp PRIVATE commsdsl::commsdsl)
