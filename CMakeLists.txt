cmake_minimum_required(VERSION 3.2)
project(rand-str-tinymt VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
add_executable(rand-str-tinymt main.cc src/random_string.cc src/tinymt32.cc)
