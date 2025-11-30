cmake_minimum_required(VERSION 3.10)

project(http LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 可将源文件放在本目录下
add_executable(
        http
        Server.h
        Server.c
        test.c
)

# 如需包含仓库顶层的 include 目录
#target_include_directories(http PRIVATE ${CMAKE_SOURCE_DIR}/include)