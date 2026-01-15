cmake_minimum_required(VERSION 3.30)
project(World)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}
    Private/World.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)