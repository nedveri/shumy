cmake_minimum_required(VERSION 3.20)

project(shumy
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(shumy STATIC
    src/FBM.cpp
    src/Perlin.cpp
    src/Value.cpp
    src/White.cpp
)

target_include_directories(shumy
    PUBLIC
        include
)

add_executable(shumyExample
    examples/main.cpp
)

target_link_libraries(shumyExample
    PRIVATE
        shumy
)