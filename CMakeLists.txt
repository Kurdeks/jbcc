project(jbcc)
cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wall -Wextra -Wpedantic)


set(USE_CCACHE YES)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
#add_subdirectory(libs)