cmake_minimum_required(VERSION 3.21)
project(SSAD)

set(CMAKE_CXX_STANDARD 17)

add_executable(SSAD main.cpp FindSumArray.h FindSubstrings.h Determinant.h least_squares_appr.h)
