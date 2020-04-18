cmake_minimum_required(VERSION 3.0.0)
project(Compiler VERSION 0.1.0)

aux_source_directory(. ALL_SRCS)
add_executable(Compiler main.cpp ${ALL_SRCS})
