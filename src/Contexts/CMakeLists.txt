cmake_minimum_required (VERSION 3.0)

include_directories(
	../src
)

add_library(
  Context STATIC
  ContextHandler.cpp
)

target_link_libraries(Context DSightBaseException)
  

