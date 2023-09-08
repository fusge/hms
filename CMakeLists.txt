cmake_minimum_required(VERSION 3.25)

include(cmake/prelude.cmake)

project(
    hms
    VERSION 0.1.0
    DESCRIPTION "The Home Management System"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

configure_file(source/hmsConfig.hpp.in source/hmsConfig.hpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
list(APPEND CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES 
    ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES}
)

# ---- Declare library ----

add_library(
    hms_lib OBJECT
    source/system.hpp source/system.cpp
)

target_include_directories(
    hms_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

find_package(asio REQUIRED)
find_package(sdbus-c++ REQUIRED)

# ---- Declare executable ----
add_executable(hms_exe source/main.cpp)
add_executable(hms::exe ALIAS hms_exe)

set_target_properties(
    hms_exe PROPERTIES
    OUTPUT_NAME hms
    EXPORT_NAME exe
)

target_link_libraries(hms_exe PRIVATE hms_lib)

include_directories(${PROJECT_BINARY_DIR}/source)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT hms_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of hms"
  )
endif()

include(cmake/dev-mode.cmake)
