cmake_minimum_required(VERSION 3.25)

project(Builder)

add_executable(builder ../build.cpp)

set_target_properties(builder PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}
        OUTPUT_NAME "builder"
)