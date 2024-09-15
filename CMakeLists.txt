cmake_minimum_required(VERSION 3.21)
project(jbcc)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add compile flags to give more compile time warnings (pedantic may be dropped later)
add_compile_options(-Wall -Wextra -Wpedantic)



find_package(GTest CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)

# using compiler cache to speed up build
set(USE_CCACHE YES)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
#add_subdirectory(libs)
