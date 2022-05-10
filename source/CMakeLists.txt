cmake_minimum_required(VERSION 3.14)

add_library(
    hms_lib OBJECT
    "system.hpp"
    "system.cpp"
)

add_executable(hms_exe "main.cpp")
add_executable(hms::exe ALIAS hms_exe)

set_target_properties(
    hms_exe PROPERTIES
    OUTPUT_NAME hms
    EXPORT_NAME exe
)

target_link_libraries(hms_exe PRIVATE hms_lib)