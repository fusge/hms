include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package hms)

install(
    TARGETS hms_exe
    RUNTIME COMPONENT hms_Runtime
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    hms_INSTALL_CMAKEDIR "${CMAKE_INSTALL_DATADIR}/${package}"
    CACHE PATH "CMake package config location relative to the install prefix"
)
mark_as_advanced(hms_INSTALL_CMAKEDIR)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${hms_INSTALL_CMAKEDIR}"
    COMPONENT hms_Development
)

# Export variables for the install script to use
install(CODE "
set(hms_NAME [[$<TARGET_FILE_NAME:hms_exe>]])
set(hms_INSTALL_CMAKEDIR [[${hms_INSTALL_CMAKEDIR}]])
set(CMAKE_INSTALL_BINDIR [[${CMAKE_INSTALL_BINDIR}]])
" COMPONENT hms_Development)

install(
    SCRIPT cmake/install-script.cmake
    COMPONENT hms_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
