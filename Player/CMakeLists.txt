cmake_minimum_required(VERSION 3.30)
project(Player)

add_library(${PROJECT_NAME}
    Private/Player.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Object
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)