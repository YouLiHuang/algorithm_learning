cmake_minimum_required(VERSION 3.10)
project(hello_algo C)

set(CMAKE_C_STANDARD 11)

include_directories(./inc)
include_directories(./)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


#add_executable(hashmap hashmap.c)
add_executable(hashlistmap hashListmap.c list.c)
