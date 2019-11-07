cmake_minimum_required(VERSION 2.8)

project(TermBook)
add_executable(${PROJECT_NAME} main.cpp forwardlist.h)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
