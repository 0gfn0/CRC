cmake_minimum_required(VERSION 3.10)

project(CRC)
include_directories(${PROJECT_SOURCE_DIR}/Include)

set(SOURCES
    Source/crc.cpp
)

add_executable(CRC ${SOURCES})
