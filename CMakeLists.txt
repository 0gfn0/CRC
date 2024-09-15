cmake_minimum_required(VERSION 3.10)

project(CRC)
include_directories(${PROJECT_SOURCE_DIR}/Include)

set(SOURCES
    Source/main.cpp
    Source/crc_8.cpp
    Source/crc_16_cms.cpp
    Source/crc_32_cksum.cpp
)

add_executable(CRC ${SOURCES})
