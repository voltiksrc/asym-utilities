cmake_minimum_required(VERSION 3.16)
project(asym-utilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(byrd src/byrd.cpp)
add_executable(cl   src/cl.cpp)
