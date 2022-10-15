cmake_minimum_required(VERSION 3.10)
project(proj02)
aux_source_directory(. DIR_SRCS)
add_executable(proj02 ${DIR_SRCS})