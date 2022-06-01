# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(hmsTests LANGUAGES CXX)

include(CTest)
# ---- Dependencies ----

find_package(GTest REQUIRED)
# include(Catch)

# ---- Tests ----

add_executable(hms_test 
  source/system_tests.cpp
  source/system_tests.hpp
)
target_link_libraries(
    hms_test PRIVATE
    hms_lib
    GTest::gtest GTest::gtest_main
)
target_compile_features(hms_test PRIVATE cxx_std_20)

add_test(NAME hms_test COMMAND hms_test)
#catch_discover_tests(hms_test)

# ---- End-of-file commands ----

add_folders(Test)
