cmake_minimum_required(VERSION 3.24)
project(Zest-Assistant)
set(CMAKE_C_STANDARD 99)

add_executable(Zest main.c help.c help.h initializePaths.c initializePaths.h library.c library.h opener.c opener.h)