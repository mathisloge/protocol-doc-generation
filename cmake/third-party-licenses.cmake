configure_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/third-party-licenses.txt.in" 
    "${CMAKE_CURRENT_BINARY_DIR}/third-party-licenses.txt"
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/third-party-licenses.txt" DESTINATION ${CMAKE_INSTALL_BINDIR}
)
