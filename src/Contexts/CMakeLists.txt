cmake_minimum_required (VERSION 3.0)

include_directories(
	../src
)

if(DEFINED USE_GLFW3)
find_package(OpenGL REQUIRED)

add_library(
	ContextGLFW3 STATIC
	ContextGLFW3.cpp
)
target_include_directories(ContextGLFW3 PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(ContextGLFW3 ${OPENGL_gl_LIBRARY})
target_link_libraries(ContextGLFW3 DSightBaseException glfw)
endif()

add_library(
	Context STATIC
	ContextHandler.cpp
)

target_link_libraries(Context DSightBaseException)
if(DEFINED USE_GLFW3)
target_link_libraries(Context ContextGLFW3)
endif()
