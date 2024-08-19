add_executable(tester tester.cpp)

target_link_libraries(tester PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tester)
