cmake_minimum_required(VERSION 3.23)
project(MyNOIPProjects C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(MyNOIPProjects
        LongestSeq.c)
