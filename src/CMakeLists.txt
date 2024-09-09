set(SOURCES ${SOURCES} main.cpp)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)


set(BISON_INPUT ${CMAKE_SOURCE_DIR}/libs/parser/parser.y)
set(FLEX_INPUT ${CMAKE_SOURCE_DIR}/libs/lexer/lexer.l)

# Bison target - generates parser.cpp and parser.hpp
BISON_TARGET(MyParser ${BISON_INPUT} ${CMAKE_SOURCE_DIR}/libs/parser/parser.cpp COMPILE_FLAGS "--defines=${CMAKE_SOURCE_DIR}/libs/parser/parser.hpp")

# Flex target - generates lexer.cpp
FLEX_TARGET(MyLexer ${FLEX_INPUT} ${CMAKE_SOURCE_DIR}/libs/lexer/lexer.cpp)

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

add_executable(jbcc ${SOURCES} )