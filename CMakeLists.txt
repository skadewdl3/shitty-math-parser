cmake_minimum_required(VERSION 3.25)
project(shitty_math_parser C)

set(CMAKE_C_STANDARD 11)

add_executable(shitty_math_parser main.c include/shitty-math-parser.c)
target_include_directories(shitty_math_parser PRIVATE include)