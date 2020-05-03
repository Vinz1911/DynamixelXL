cmake_minimum_required(VERSION 3.13)
project(DynamixelXL)
include_directories(/usr/local/include/dynamixel_sdk)
link_libraries(-ldxl_sbc_cpp)
link_libraries(-lrt)

set(CMAKE_CXX_STANDARD 17)

add_executable(DynamixelDemo example/main.cpp)
install(FILES src/dynamixel_xl.h src/dynamixel_xl.cpp src/dynamixel_table.cpp DESTINATION /usr/local/include/DynamixelXL)