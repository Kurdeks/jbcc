set(SOURCES ${SOURCES} main.cpp)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)


set(BISON_INPUT ${CMAKE_SOURCE_DIR}/src/parser.y)
set(FLEX_INPUT ${CMAKE_SOURCE_DIR}/src/lexer.l)

# Bison target - generates parser.cpp and parser.hpp
BISON_TARGET(MyParser ${BISON_INPUT} ${CMAKE_SOURCE_DIR}/src/parser.cpp COMPILE_FLAGS "--defines=${CMAKE_SOURCE_DIR}/parser.hpp")

# Flex target - generates lexer.cpp
FLEX_TARGET(MyLexer ${FLEX_INPUT} ${CMAKE_SOURCE_DIR}/src/lexer.cpp)

# Ensure Bison is run before Flex
ADD_FLEX_BISON_DEPENDENCY(MyLexer MyParser)

# Include directory for generated headers
include_directories(${CMAKE_BINARY_DIR})

# Specify main source files
set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyLexer_OUTPUTS}
)

# Add executable
add_executable(MyProject ${SOURCES})

#
#BISON_TARGET(MyParser ../src/parser.y ../../src/parser.cpp
#             DEFINES_FILE ../../src/parser.h)
             
#ADD_FLEX_BISON_DEPENDENCY(MyLexer MyParser)

add_executable(jbcc ${SOURCES} ${BISON_MyParser_OUTPUTS})