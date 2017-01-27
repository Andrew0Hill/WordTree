cmake_minimum_required(VERSION 3.6)
project(WordTree)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c main.h)
add_executable(WordTree ${SOURCE_FILES})