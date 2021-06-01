cmake_minimum_required(VERSION 3.17)
project(XML_helper)

set(CMAKE_CXX_STANDARD 14)

add_executable(XML_helper main.cpp XML_Node.cpp XML_Node.h XML_Data.cpp XML_Data.h)