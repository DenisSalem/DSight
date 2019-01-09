#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/DSightBaseException.hpp"
#include "ContextHandler.hpp"
#include <iostream>

namespace DSight {
	template <typename ContextClass>
	int ContextHandler<ContextClass>::context_count = 0;

	template <typename ContextClass>
	ContextHandler<ContextClass>::ContextHandler(ContextCode context_code, int maj, int min) {
		if (ContextHandler::context_count > 0) {
			throw DSightBaseException("Multiple Context.", DSIGHT_EXCEPTION_MULTIPLE_CONTEXT);
		}
		else {
			ContextHandler::context_count += 1;
			switch (context_code) {
				#ifdef _USE_GLFW3_
				case DSIGHT_CONTEXT_GLFW3:
					m_wrapper = new ContextGLFW3();
					break;
				#endif
				default:
					ContextHandler::context_count = 0;
					throw DSightBaseException("Unsupported Context", DSIGHT_EXCEPTION_UNSUPPORTED_CONTEXT);
			}
		}
	}
	
	template <typename ContextClass>
	ContextHandler<ContextClass>::~ContextHandler() {
		delete m_wrapper;
	}
	#ifdef _USE_GLFW3_
	template class ContextHandler<ContextGLFW3>;
	#endif
}
