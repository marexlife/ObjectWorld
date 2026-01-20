cmake_minimum_required(VERSION 3.30)
project(App)

include(${CMAKE_SOURCE_DIR}/cmake/flags.cmake)

add_library(${PROJECT_NAME}
    Private/App.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Window
    World
    Player
)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    spdlog::spdlog_header_only
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)

target_compile_options(${PROJECT_NAME} PUBLIC
    ${CUSTOM_FLAGS}
)
