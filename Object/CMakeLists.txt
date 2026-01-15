cmake_minimum_required(VERSION 3.30)
project(Object)

add_library(${PROJECT_NAME}
    Private/Object.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)