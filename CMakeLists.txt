cmake_minimum_required(VERSION 3.6)
project(file_test)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c joinMsg.c common.h CollegeInterface.c UserInterface.c Common.c User.c College.c Match.c AdminInterface.c KM.c test.c)
add_executable(file_test ${SOURCE_FILES})