cmake_minimum_required(VERSION 2.8)

project(TermBook)
add_executable(${PROJECT_NAME} main.cpp forwardlist.h)

#target_sources(${PROJECT_NAME} termlist.cpp)

set(CMAKE_CXX_STANDARD 17)
