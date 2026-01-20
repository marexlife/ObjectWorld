cmake_minimum_required(VERSION 3.30)
project(Object)

include(${CMAKE_SOURCE_DIR}/cmake/flags.cmake)

add_library(${PROJECT_NAME}
    Private/Object.cpp
    Private/Name.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)

target_compile_options(${PROJECT_NAME} PUBLIC
    ${CUSTOM_FLAGS}
)