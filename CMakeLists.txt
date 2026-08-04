cmake_minimum_required(VERSION 4.2)
project(ascii_clock)

set(CMAKE_CXX_STANDARD 20)

add_executable(ascii_clock main.cpp
        ascii_numbers.h
        clock_time.cpp
        clock_time.h
        terminal_display.cpp
)
