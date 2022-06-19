cmake_minimum_required(VERSION 3.17.5)
project(lib C)

set(CMAKE_C_STANDARD 99)
include_directories("/usr/local/include/gsl")
add_library(library SHARED library.h library.c)
