cmake_minimum_required(VERSION 2.8)

project(TermBook)
message(${PROJECT_NAME})
#set( CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} main.cpp forwardlist.h)
