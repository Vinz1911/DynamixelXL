CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(Dynamixel CXX)

INCLUDE_DIRECTORIES(/usr/local/include/dynamixel_sdk)

IF(CMAKE_SYSTEM_NAME STREQUAL Linux)
    IF(CMAKE_SYSTEM_PROCESSOR STREQUAL arm)
        LINK_LIBRARIES(-ldxl_sbc_cpp)
    ENDIF()
    IF(CMAKE_SYSTEM_PROCESSOR STREQUAL x86_64 OR CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL amd64)
        LINK_LIBRARIES(-ldxl_x64_cpp)
    ENDIF()
    LINK_LIBRARIES(-lrt)
ENDIF()

SET(CMAKE_CXX_STANDARD 17)

ADD_EXECUTABLE(DynamixelDemo example/main.cpp src/dynamixel.cpp)
# install(FILES src/dynamixel.h src/dynamixel.cpp src/dynamixel_address_table.h DESTINATION /usr/local/include/Dynamixel)