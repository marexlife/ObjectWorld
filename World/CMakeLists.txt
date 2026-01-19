cmake_minimum_required(VERSION 3.30)
project(World)

include(${CMAKE_SOURCE_DIR}/cmake/flags.cmake)

add_library(${PROJECT_NAME}
    Private/World.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Object
    Player
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)