#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/DSightBaseException.hpp"
#include "ContextGLFW3.hpp"

namespace DSight {
	ContextGLFW3::ContextGLFW3() {
		if (!glfwInit()) {
			throw DSightBaseException("Context Initialization failed.", DSIGHT_EXCEPTION_CONTEXT_INIT_FAILED);
		}	
		m_surfaces.push_back(glfwCreateWindow(640, 480, "Hello World", NULL, NULL));
		if (!m_surfaces.back()) {
			glfwTerminate();
			throw DSightBaseException("Context Initialization failed.", DSIGHT_EXCEPTION_CONTEXT_INIT_FAILED);
		}
		auto window = m_surfaces.back();
		glfwMakeContextCurrent(window);
		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	
	ContextGLFW3::~ContextGLFW3() {
		glfwTerminate();
	}
}
