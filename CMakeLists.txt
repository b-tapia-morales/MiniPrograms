cmake_minimum_required(VERSION 3.25)
project(MiniPrograms C)

set(CMAKE_C_STANDARD 23)

add_executable(MiniPrograms binary_converter.h hexadecimal_converter.h bulls_and_cows_arr.h main.c bulls_and_cows.h last_digit_verifier.h)
