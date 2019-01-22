cmake_minimum_required (VERSION 3.0)

include_directories(
	../src
)

add_library(
	Viewport STATIC
	Viewport.cpp
)
target_link_libraries(Viewport DSightBaseException Charts)
