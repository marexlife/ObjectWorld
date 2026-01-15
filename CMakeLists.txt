cmake_minimum_required(VERSION 3.30)
project(game)

add_subdirectory(Main)
add_subdirectory(World)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
