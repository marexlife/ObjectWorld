cmake_minimum_required(VERSION 3.30)
project(Main)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    Private/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    World
)