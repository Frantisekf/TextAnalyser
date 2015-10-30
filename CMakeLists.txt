cmake_minimum_required(VERSION 3.3)
project(Projekt1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES proj1.c    )
add_executable(Projekt1 ${SOURCE_FILES})