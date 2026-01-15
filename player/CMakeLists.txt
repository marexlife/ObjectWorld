cmake_minimum_required(VERSION 3.30)
project(player)

add_library(${PROJECT_NAME}
    Private/Player.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    object
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)