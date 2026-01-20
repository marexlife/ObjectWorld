cmake_minimum_required(VERSION 3.30)
project(Window)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}
    Private/Window.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Object
)

target_compile_options(${PROJECT_NAME} PUBLIC
    ${CUSTOM_FLAGS}
)
