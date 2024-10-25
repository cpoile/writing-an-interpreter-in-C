cmake_minimum_required(VERSION 3.26)
project(writing_an_interpreter C)

set(CMAKE_C_STANDARD 17)

set(CMAKE_C_FLAGS "-Wall -Wpedantic")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_executable(writing_an_interpreter all.c)
