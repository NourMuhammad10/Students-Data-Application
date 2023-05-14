cmake_minimum_required(VERSION 3.24)
project(Students-Data_Application)

set(CMAKE_CXX_STANDARD 14)

add_executable(Students-Data-Application
        BinarySearchTree/BinarySearchTree.cpp
        BinarySearchTree/BinarySearchTree.h
        main.cpp Student/Student.h Student/Student.cpp LoadFile.cpp)