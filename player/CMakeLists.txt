cmake_minimum_required(VERSION 3.30)
project(player)

add_library(${PROJECT_NAME}
    Private/Player.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)