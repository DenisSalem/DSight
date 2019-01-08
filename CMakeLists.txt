cmake_minimum_required (VERSION 3.0.2)
project(DSight)
enable_testing()

add_subdirectory(src/Exceptions)
add_subdirectory(src/Contexts)
add_subdirectory(test)

add_test(TestContextHandler test/TestContextHandler)
