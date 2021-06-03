cmake_minimum_required(VERSION 3.17.5)
project(WarehouseStructureOnLists)

set(CMAKE_CXX_STANDARD 14)

add_executable(warehouse main.cpp StaticList.h Colors.h Cell.cpp Cell.h Section.cpp Section.h List.h Warehouse.cpp menuUtils.h menuUtils.cpp)
