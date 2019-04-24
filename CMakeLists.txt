cmake_minimum_required(VERSION 3.13)

project(ray_tracing_weekend VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(test)
