cmake_minimum_required(VERSION 3.30)
project(Main)

include(${CMAKE_SOURCE_DIR}/cmake/flags.cmake)

add_executable(${PROJECT_NAME}
    Private/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    App
    Window
    World
    Object
    Player
)

target_compile_options(${PROJECT_NAME} PUBLIC
    ${CUSTOM_FLAGS}
)