cmake_minimum_required(VERSION 3.10)

project(NetStack)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 添加各个子项目目录
add_subdirectory(
        application/http
)