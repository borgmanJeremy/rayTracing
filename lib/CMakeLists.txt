cmake_minimum_required(VERSION 3.14)
project(ray_tracing_weekend_lib VERSION 0.0.1 LANGUAGES CXX)

add_library(ray_tracing_lib)
target_compile_options(ray_tracing_lib PRIVATE -Wall -Wextra -Wpedantic)

target_sources(ray_tracing_lib
  PRIVATE
    "src/flat_image.cpp"
    "src/ray_tracing.cpp"
)

target_include_directories(ray_tracing_lib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/>
)


