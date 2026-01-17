cmake_minimum_required(VERSION 3.30)
project(app)

include(${CMAKE_SOURCE_DIR}/cmake/flags.cmake)

add_library(${PROJECT_NAME}
    Private/App.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    window
    world
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)