#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/DSightBaseException.hpp"
#include "ContextGLFW3.hpp"

namespace DSight {
	ContextGLFW3::ContextGLFW3(int maj, int min) {
		if (!glfwInit()) {
			throw DSightBaseException("Context Initialization failed.", DSIGHT_EXCEPTION_CONTEXT_INIT_FAILED);
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, maj);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, min);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//CreateSurface();
	}
	
	void ContextGLFW3::CreateCanvas() {
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); 
		m_windows.push_back(glfwCreateWindow(640, 480, "Hello World", NULL, NULL));
		if (!m_windows.back()) {
			glfwTerminate();
			throw DSightBaseException("Canvas creation failed.", DSIGHT_EXCEPTION_CANVAS_CREATION_FAILED);
		}	
	}

	void ContextGLFW3::LoopRender() {
		auto window = m_windows.back();
		glfwMakeContextCurrent(window);
		glfwShowWindow(window);
		while (!glfwWindowShouldClose(window))
		{
			// Callback designer.
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwDestroyWindow(window);
	}
	
	void ContextGLFW3::DeleteCanvas(unsigned int index ) {
		size_t size = m_windows.size();
		if (index < size) {
			glfwDestroyWindow(m_windows[index]);
			m_windows.erase(m_windows.begin() + index);
			return;
		}
		throw DSightBaseException("Canvas doesn't exists.", DSIGHT_EXCEPTION_CANVAS_DOESNT_EXISTS);
	}

	ContextGLFW3::~ContextGLFW3() {
		glfwTerminate();
	}
}
