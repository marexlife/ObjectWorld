cmake_minimum_required(VERSION 3.30)
project(world)

include(${CMAKE_SOURCE_DIR}/cmake/flags.cmake)

add_library(${PROJECT_NAME}
    Private/World.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    object
    player
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)