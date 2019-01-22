cmake_minimum_required (VERSION 3.0)

include_directories(
	../src
)

add_library(
	Canvas STATIC
	Canvas.cpp
)
target_link_libraries(Canvas DSightBaseException Viewport)
