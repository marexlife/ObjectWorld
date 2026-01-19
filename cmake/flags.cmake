set(COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

set(CUSTOM_FLAGS
    -O3
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    set(${CUSTOM_FLAGS}
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wnrvo
        -Werror
    )
endif()

