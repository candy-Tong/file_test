cmake_minimum_required(VERSION 3.6)
project(file_test)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c user.h match.h common.h)
add_executable(file_test ${SOURCE_FILES})