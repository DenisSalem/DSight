cmake_minimum_required (VERSION 3.0.2)
project(DSight)
enable_testing()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(PACKAGE_VERSION "0.0.0")
set(USE_GLFW3 "1")

if(USE_GLFW3)
	add_definitions(-D_USE_GLFW3_)
endif()

add_subdirectory(src/Exceptions)
add_subdirectory(src/Charts)
add_subdirectory(src/Contexts)
add_subdirectory(Python)

add_subdirectory(test)
add_test(ContextHandler test/ContextHandler)
