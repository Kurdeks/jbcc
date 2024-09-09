set(SOURCES ${SOURCES} main.cpp)

find_package(BISON REQUIRED)
BISON_TARGET(MyParser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
             DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.h)

add_executable(jbcc ${SOURCES} ${BISON_MyParser_OUTPUTS})