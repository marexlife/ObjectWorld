cmake_minimum_required(VERSION 3.30)
project(main)

include(${CMAKE_SOURCE_DIR}/cmake/flags.cmake)

add_executable(${PROJECT_NAME}
    Private/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    app
    world
    object
    player
)