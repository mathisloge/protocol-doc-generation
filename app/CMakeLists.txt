
add_executable(protodoc
    src/main.cpp
)

set_property(TARGET protodoc PROPERTY CXX_STANDARD 20)

target_link_libraries(protodoc PRIVATE 
    protodoc::libprotodoc
    commsdsl::commsdsl
)
