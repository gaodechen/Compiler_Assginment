cmake_minimum_required(VERSION 3.0.0)
project(Compiler VERSION 0.1.0)

aux_source_directory(./common ALL_SRCS)
aux_source_directory(./file_reader ALL_SRCS)
aux_source_directory(./lexer ALL_SRCS)
aux_source_directory(./parser ALL_SRCS)
aux_source_directory(./machine ALL_SRCS)

add_executable(Compiler main.cpp ${ALL_SRCS})

set(CMAKE_BUILD_TYPE "debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
