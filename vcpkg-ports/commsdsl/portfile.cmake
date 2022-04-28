vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO commschamp/commsdsl
    REF 7457197efb0586dbd2aa1bccf7e0e49e06dbf5c0
    SHA512 5a3d6e51dfb1c38092d5caa2a637ee88ddcc4b6cba28813f58bfcfe1bbd3ca96733df4772eb9086b898f03d964d6a13fd4b35aff31a9fb506553fd65fb238a18
    HEAD_REF master
)

vcpkg_configure_cmake(
    SOURCE_PATH "${SOURCE_PATH}"
    PREFER_NINJA
    OPTIONS
        -DCOMMSDSL_NO_COMMS_CHAMPION=ON
        -DCOMMSDSL_BUILD_APPS=ON
        -DCOMMSDSL_INSTALL_APPS=ON
        -DCOMMSDSL_CHECKOUT_COMMS_CHAMPION=OFF
        -DCOMMSDSL_BUILD_UNIT_TESTS=OFF
        -DCOMMSDSL_WARN_AS_ERR=OFF
)
vcpkg_install_cmake()

vcpkg_copy_tools(
    TOOL_NAMES commsdsl2comms
    AUTO_CLEAN
)

vcpkg_fixup_cmake_targets(CONFIG_PATH lib/LibCommsdsl/cmake TARGET_PATH share/LibCommsdsl)
# after fixing the following dirs are empty
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/lib/LibCommsdsl")
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/lib/LibCommsdsl")

if(VCPKG_LIBRARY_LINKAGE STREQUAL "static")
    file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/bin" "${CURRENT_PACKAGES_DIR}/debug/bin")
endif()
# Handle copyright
file(INSTALL "${SOURCE_PATH}/LICENSE.txt" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}" RENAME copyright)
