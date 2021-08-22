function(protodoc_generate SETTINGS_FILE TARGET_NAME)
    set(_gen_settings "${CMAKE_CURRENT_BINARY_DIR}/protodoc_${PROJECT_NAME}.json")
    configure_file("${SETTINGS_FILE}" "${_gen_settings}")
    add_custom_target("${TARGET_NAME}"
        COMMAND protodoc::protodoc -s "${_gen_settings}"
    )
endfunction()
