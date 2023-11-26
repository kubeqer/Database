cmake_minimum_required(VERSION 3.25)
project ("DATABASE")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_compile_options(-Wall -Wextra)
set(CMAKE_CXX_STANDARD 20)

add_executable(DATABASE src/main.cpp
        src/Part.cpp src/Part.h
        src/PartStore.cpp src/PartStore.h
        src/Database.cpp src/Database.h
)
