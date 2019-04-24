cmake_minimum_required(VERSION 3.13)
project(ray_tracing_weekend_lib VERSION 0.0.1 LANGUAGES CXX)

add_library(ray_tracing_lib)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(ray_tracing_lib PRIVATE -Wall -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(ray_tracing_lib PRIVATE -Wall -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
   target_compile_options(ray_tracing_lib PRIVATE -W3)
endif()

target_sources(ray_tracing_lib
  PRIVATE
    "src/object.cpp"  
    "src/flat_image.cpp"
    "src/vec_4f.cpp"
    "src/material.cpp"  
    "src/ray.cpp"
    )

target_include_directories(ray_tracing_lib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/>
)

set_target_properties(ray_tracing_lib PROPERTIES CXX_STANDARD 17)
