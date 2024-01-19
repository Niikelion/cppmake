cmake_minimum_required(VERSION 3.25)

find_package(CppMake REQUIRED CONFIG)

project(Builder)

add_executable(builder ../build.cpp)
target_link_libraries(builder PRIVATE CppMake::CppMakeLib)

set_target_properties(builder PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}
        OUTPUT_NAME "builder"
)