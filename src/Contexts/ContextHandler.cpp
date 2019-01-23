#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/DSightBaseException.hpp"
#include "ContextHandler.hpp"

namespace DSight {
	//~ template <typename ContextClass>
	int ContextHandler::context_count = 0;

	//~ template <typename ContextClass>
	ContextHandler::ContextHandler(ContextCode context_code, int maj, int min) : m_context_code(context_code) {
		if (ContextHandler::context_count > 0) {
			throw DSightBaseException("Multiple Context.", DSIGHT_EXCEPTION_MULTIPLE_CONTEXT);
		}
		else {
			ContextHandler::context_count += 1;
			switch (context_code) {
				#ifdef _USE_GLFW3_
				case DSIGHT_CONTEXT_GLFW3:
					m_wrapper = new DSight::ContextGLFW3(maj, min);
					break;
				#endif
				default:
					ContextHandler::context_count = 0;
					throw DSightBaseException("Unsupported Context", DSIGHT_EXCEPTION_UNSUPPORTED_CONTEXT);
			}
		}
	}
	
	//~ template <typename ContextClass>
	Canvas * ContextHandler::AddCanvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision) {
		m_wrapper->CreateCanvas();
		m_canvas.push_back(
			new Canvas(horizontal_subdivision, vertical_subdivision)
		);
		return m_canvas.back();
	}
	
	ContextHandler::~ContextHandler() {
		for (unsigned int i = 0; i< m_canvas.size(); i++) {
			delete m_canvas[i];
		}
		
		switch (m_context_code) {
			case DSight::DSIGHT_CONTEXT_GLFW3:
				((ContextGLFW3 *) m_wrapper)->~ContextGLFW3();
				break;
				
			default:
				break;
		}
		ContextHandler::context_count = 0;
	}
	
	//~ #ifdef _USE_GLFW3_
	//~ template class ContextHandler<ContextGLFW3>;
	//~ #endif
}
