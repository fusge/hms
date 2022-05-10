cmake_minimum_required(VERSION 3.14)

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
set(CMAKE_CXX_STANDARD_20)
set(CMAKE_CXX_STANDARD_REQUIRED)

add_subdirectory(source)

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
