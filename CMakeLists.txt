cmake_minimum_required(VERSION 3.30)
project(oworld)

include(${CMAKE_SOURCE_DIR}/cmake/deps.cmake)

add_subdirectory(main)
add_subdirectory(app)
add_subdirectory(window)
add_subdirectory(object)
add_subdirectory(player)
add_subdirectory(world)
