cmake_minimum_required(VERSION 3.11)
project(BTree)

set(CMAKE_CXX_STANDARD 11)

add_executable(BTree main.cpp BTree.cpp BTree.h)