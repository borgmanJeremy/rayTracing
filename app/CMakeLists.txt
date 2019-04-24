cmake_minimum_required(VERSION 3.13)
project(ray_tracing_weekend_app VERSION 0.0.1 LANGUAGES CXX)

add_executable(ray_tracing_object_app)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  target_compile_options(ray_tracing_object_app PRIVATE -Wall -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(ray_tracing_object_app PRIVATE -Wall -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
   target_compile_options(ray_tracing_object_app PRIVATE -W3)
endif()

target_sources(ray_tracing_object_app
  PRIVATE
  "src/main_object.cpp"
)

target_include_directories(ray_tracing_object_app
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../../lib/include"
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(threadLib pThread)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	set(threadLib pThread)
endif()

target_link_libraries(
  ray_tracing_object_app
  PRIVATE
		$threadLib
    ray_tracing_lib)
