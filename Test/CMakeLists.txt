
add_subdirectory(googletest)

set(TEST_SOURCES
        testActivity.cpp
        runAllTests.cpp
        testRegister.cpp
        ../Activity.cpp
        ../Register.cpp
)

add_executable(runAllTests ${TEST_SOURCES})

target_link_libraries(runAllTests
        GTest::gtest
        GTest::gtest_main
        pthread
)

include(GoogleTest)
gtest_discover_tests(runAllTests)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(runAllTests ${CURSES_LIBRARIES})

