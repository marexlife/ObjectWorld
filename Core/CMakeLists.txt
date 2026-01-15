cmake_minimum_required(VERSION 3.30)
project(Core)

add_library(${PROJECT_NAME}
    Private/Core.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)