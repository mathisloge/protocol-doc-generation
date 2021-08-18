vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO mathisloge/inja
    REF fc6fa5ec0477df2b61d0becf30ae2d56338eee3f
    SHA512 e560d3c4234e1a05d47c27ba188240377e1000b0dbe75ebb188fd1da93c0a938c8343c1735fd4727cd83cea92703a843b838cc4feaf4ac01c543b7cea6e1ee68
    HEAD_REF master
)

vcpkg_configure_cmake(
    SOURCE_PATH "${SOURCE_PATH}"
    PREFER_NINJA
    OPTIONS
        -DINJA_USE_EMBEDDED_JSON=OFF
        -DBUILD_TESTING=OFF
        -DBUILD_BENCHMARK=OFF
        -DINJA_TYPES_FILE="${CMAKE_CURRENT_LIST_DIR}/types.hpp.in"
)

vcpkg_install_cmake()
vcpkg_fixup_cmake_targets(CONFIG_PATH lib/cmake/inja)
vcpkg_copy_pdbs()

# Inja is a header-only library
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug")
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/lib")
# Don't need built-in nlohmann-json as this package depends on nlohmann-json
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/include/inja/json")

file(INSTALL ${SOURCE_PATH}/LICENSE DESTINATION ${CURRENT_PACKAGES_DIR}/share/${PORT} RENAME copyright)
