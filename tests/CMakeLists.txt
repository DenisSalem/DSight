cmake_minimum_required (VERSION 3.0)

include_directories(
	../src
)

add_executable(
	ContextHandler
	TestContextHandler.cpp
)

target_link_libraries(ContextHandler Context)

