cmake_minimum_required(VERSION 3.30)
project(ProgettoEsame)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProgettoEsame main.cpp
        Activity.h
        Activity.cpp
        Register.cpp
        Register.h
        Menu.cpp
        Menu.h
)

#NCurses
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(ProgettoEsame ${CURSES_LIBRARIES})


#GoogleTest
enable_testing()
add_subdirectory(Test)


