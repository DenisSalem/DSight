#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/BaseException.hpp"
#include "../Exceptions/ExceptionMessages.hpp"
#include "ContextGLFW3.hpp"
#include <iostream>

namespace DSight {	
	ContextGLFW3::ContextGLFW3(int maj, int min) {
		if (!glfwInit()) {
			throw DSight::BaseException(DSIGHT_MSG_CONTEXT_INIT_FAILED, ExceptionCode::CONTEXT_INIT_FAILED);
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, maj);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, min);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
	}
	
	void ContextGLFW3::CreateCanvas() {
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); 
		m_windows.push_back(glfwCreateWindow(640, 480, "Hello World", NULL, NULL));
		if (!m_windows.back()) {
			glfwTerminate();
			throw DSight::BaseException(DSIGHT_MSG_CANVAS_CREATION_FAILED, ExceptionCode::CANVAS_CREATION_FAILED);
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
		throw DSight::BaseException(DSIGHT_MSG_CANVAS_DOESNT_EXISTS, ExceptionCode::CANVAS_DOESNT_EXISTS);
	}

	ContextGLFW3::~ContextGLFW3() {
		glfwTerminate();
	}
}
