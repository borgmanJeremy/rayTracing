cmake_minimum_required(VERSION 3.14)
project(ray_tracing_weekend_app VERSION 0.0.1 LANGUAGES CXX)

add_executable(ray_tracing_app)
target_compile_options(ray_tracing_app PRIVATE -Wall -Wextra -Wpedantic)

target_sources(ray_tracing_app
  PRIVATE
    "src/main.cpp"
)

target_include_directories(ray_tracing_app
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(
  ray_tracing_app
  PRIVATE
  ray_tracing_lib)
