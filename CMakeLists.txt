cmake_minimum_required(VERSION 3.6)
project(Algorithm_Cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h Student.h heap.h Heap.h Sort.h binarySearch.h Union.h)
add_executable(Algorithm_Cpp ${SOURCE_FILES})