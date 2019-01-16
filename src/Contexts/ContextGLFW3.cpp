#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/DSightBaseException.hpp"
#include "ContextGLFW3.hpp"
#include <iostream>

namespace DSight {
	ContextGLFW3::ContextGLFW3() {
		if (!glfwInit()) {
			throw DSightBaseException("Context Initialization failed.", DSIGHT_EXCEPTION_CONTEXT_INIT_FAILED);
		}
		CreateSurface();
	}
	
	int ContextGLFW3::CreateSurface() {
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); 
		m_surfaces.push_back(glfwCreateWindow(640, 480, "Hello World", NULL, NULL));
		if (!m_surfaces.back()) {
			glfwTerminate();
			throw DSightBaseException("Surface creation failed.", DSIGHT_EXCEPTION_SURFACE_CREATION_FAILED);
		}	
	}

	void ContextGLFW3::TestDisplayWindow() {
		auto window = m_surfaces.back();
		glfwMakeContextCurrent(window);
		glfwShowWindow(window);
		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		/*glfwTerminate();*/
	}
	
	void ContextGLFW3::DeleteSurface(int index ) {
		size_t size = m_surfaces.size();
		if (index < size && index >= 0) {
			glfwDestroyWindow(m_surfaces[index]);
			m_surfaces.erase(m_surfaces.begin() + index);
			return;
		}
		throw DSightBaseException("Surface doesn't exists.", DSIGHT_SURFACE_DOESNT_EXISTS);
	}

	
	ContextGLFW3::~ContextGLFW3() {
		glfwTerminate();
	}
}
