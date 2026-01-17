cmake_minimum_required(VERSION 3.30)
project(window)

include(${CMAKE_SOURCE_DIR}/cmake/flags.cmake)

add_library(${PROJECT_NAME}
    Private/Window.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    object
)

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    SDL2::SDL2main
)
