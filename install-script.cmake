file(
    RELATIVE_PATH relative_path
    "/${hms_INSTALL_CMAKEDIR}"
    "/${CMAKE_INSTALL_BINDIR}/${hms_NAME}"
)

get_filename_component(prefix "${CMAKE_INSTALL_PREFIX}" ABSOLUTE)
set(config_dir "${prefix}/${hms_INSTALL_CMAKEDIR}")
set(config_file "${config_dir}/hmsConfig.cmake")

message(STATUS "Installing: ${config_file}")
file(WRITE "${config_file}" "\
get_filename_component(
    _hms_executable
    \"\${CMAKE_CURRENT_LIST_DIR}/${relative_path}\"
    ABSOLUTE
)
set(
    HMS_EXECUTABLE \"\${_hms_executable}\"
    CACHE FILEPATH \"Path to the hms executable\"
)
")
list(APPEND CMAKE_INSTALL_MANIFEST_FILES "${config_file}")
