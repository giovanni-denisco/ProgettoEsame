
add_subdirectory(googletest)

set(TEST_SOURCES
        test.cpp
        runAllTests.cpp
        ../functions.cpp
)

add_executable(runAllTests ${TEST_SOURCES})

target_link_libraries(runAllTests
        GTest::gtest
        GTest::gtest_main
        pthread
)

include(GoogleTest)
gtest_discover_tests(runAllTests)



