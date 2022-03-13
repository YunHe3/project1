cmake_minimum_required(VERSION 3.21)
project(project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project1
        calculator.cpp
        data_structre.cpp
        data_structure.h
        demo1.cpp
        Header.h
        platform.cpp
        sql_interpreter.cpp
        toolbox.cpp calculator.h)
