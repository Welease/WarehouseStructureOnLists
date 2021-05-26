cmake_minimum_required(VERSION 3.19)
project(kursach)

set(CMAKE_CXX_STANDARD 14)

add_executable(kursach main.cpp StaticList.h Colors.h Cell.cpp Cell.h Section.cpp Section.h List.h)