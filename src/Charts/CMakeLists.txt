cmake_minimum_required (VERSION 3.0)

include_directories(
	../src
)

set(
	CHART_SOURCE
	Chart.cpp
	Histogram.cpp
	HistogramCPU.cpp
)

if(DEFINED USE_GLFW3)
set(
	CHART_SOURCE
	${CHART_SOURCE}
	HistogramGL.cpp
)

message(STATUS "!!! DEPS: ${CHART_SOURCE} !!!")
endif()


add_library(
	Charts STATIC
	${CHART_SOURCE}
)

if(DEFINED USE_GLFW3)
find_package(OpenGL REQUIRED)
target_include_directories(Charts PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(Charts ${OPENGL_gl_LIBRARY})
endif()


