cmake_minimum_required (VERSION 3.0.2)
project(DSight)
enable_testing()

set(PACKAGE_VERSION "0.0.0")
set(USE_GLFW3 "1")

if(USE_GLFW3)
add_definitions(-D_USE_GLFW3_)
endif()

add_subdirectory(src/Exceptions)
add_subdirectory(src/Contexts)
add_subdirectory(Python)
add_subdirectory(test)

add_test(ContextHandler test/ContextHandler)
