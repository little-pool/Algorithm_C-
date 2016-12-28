cmake_minimum_required(VERSION 3.6)
project(Algorithm_Cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    binarySearch.h
    Graph.h
    Heap.h
    main.cpp
    Sort.h
    SortTestHelper.h
    Student.h
    Union.h ReadGraph.h)

add_executable(Algorithm_Cpp ${SOURCE_FILES})