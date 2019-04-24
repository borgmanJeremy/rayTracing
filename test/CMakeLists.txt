cmake_minimum_required(VERSION 3.13)
project(ray_tracing_test VERSION 0.0.1 LANGUAGES CXX)

add_executable(ray_tracing_test)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(ray_tracing_lib PRIVATE -Wall -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(ray_tracing_lib PRIVATE -Wall -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
   target_compile_options(ray_tracing_lib PRIVATE -W3)
endif()

target_sources(ray_tracing_test
  PRIVATE
    "src/test_vec_4f.cpp"
)

target_include_directories(ray_tracing_test
  PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/../../lib/include"
)

target_link_libraries(
  ray_tracing_test
  PRIVATE
  ray_tracing_lib
  )
