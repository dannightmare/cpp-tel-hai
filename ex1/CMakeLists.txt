cmake_minimum_required(VERSION 3.23)
project(cpp_ex1)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_ex1 main.cpp ObservationCLI.cpp ObservationCLI.h ObservationNode.cpp ObservationNode.h)
