cmake_minimum_required (VERSION 3.0)

include_directories(
	../src
)

add_executable(
	TestContextHandler
	TestContextHandler.cpp
)
target_link_libraries(TestContextHandler Context)

add_executable(
	TestCanvas
	TestCanvas.cpp
)
target_link_libraries(TestCanvas Canvas Context)

