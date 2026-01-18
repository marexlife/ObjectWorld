cmake_minimum_required(VERSION 3.30)
project(main)

include(${CMAKE_SOURCE_DIR}/cmake/flags.cmake)

add_executable(${PROJECT_NAME}
    Private/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    app
    window
    world
    object
    player
)


find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)
