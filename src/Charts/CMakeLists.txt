cmake_minimum_required (VERSION 3.0)

include_directories(
	../src
)

add_library(
	Histogram STATIC
	Histogram.cpp
	HistogramCPU.cpp
)

if(DEFINED USE_GLFW3)
find_package(OpenGL REQUIRED)

add_library(
	HistogramGL STATIC
	HistogramGL.cpp
)

target_include_directories(HistogramGL PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(HistogramGL ${OPENGL_gl_LIBRARY})
target_link_libraries(Histogram HistogramGL)
endif()


