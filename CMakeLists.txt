cmake_minimum_required(VERSION 3.25)
project(Student_Information_Management_System)

set(CMAKE_CXX_STANDARD 23)

add_executable(Student_Information_Management_System Student.h Student.cpp Administrator.h Administrator.cpp main.cpp)