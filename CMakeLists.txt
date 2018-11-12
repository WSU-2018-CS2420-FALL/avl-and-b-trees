cmake_minimum_required(VERSION 3.10)
project(avl_and_b_trees)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
  
add_executable(main src/main.cpp )

add_executable(tester test/tester.cpp)
