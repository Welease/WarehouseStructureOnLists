cmake_minimum_required(VERSION 3.17.5)
project(WarehouseStructureOnLists)

set(CMAKE_CXX_STANDARD 14)

add_executable(kursach main.cpp StaticList.h Colors.h Cell.cpp Cell.h Section.cpp Section.h List.h Warehouse.cpp)
add_executable(test main.cpp)