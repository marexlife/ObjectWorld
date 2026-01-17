cmake_minimum_required(VERSION 3.30)
project(oworld)

include(${CMAKE_SOURCE_DIR}/cmake/deps.cmake)

CUSTOM_DEPS(third_party)

add_subdirectory(main)
add_subdirectory(app)
add_subdirectory(window)
add_subdirectory(object)
add_subdirectory(player)
add_subdirectory(world)
