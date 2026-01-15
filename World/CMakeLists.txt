cmake_minimum_required(VERSION 3.30)
project(World)

add_library(${PROJECT_NAME} PRIVATE
    Private/World.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)