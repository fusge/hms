cmake_minimum_required(VERSION 3.24)

add_library(
    hms_lib OBJECT
    system.hpp system.cpp
)

add_executable(hms_exe 
    main.cpp
)

target_link_libraries(hms_exe PRIVATE hms_lib)

add_executable(hms::exe ALIAS hms_exe)

set_target_properties(
    hms_exe PROPERTIES
    OUTPUT_NAME hms
    EXPORT_NAME exe
)

