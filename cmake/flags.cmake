set(COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

if(MSVC)
    set(CUSTOM_FLAGS 
        /O3
        /W4
    )
else()
    set(CUSTOM_FLAGS
        -O3
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Werror
    )
endif()
