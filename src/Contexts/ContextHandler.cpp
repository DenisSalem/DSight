#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/DSightBaseException.hpp"
#include "ContextHandler.hpp"
#include <iostream>

namespace DSight {
	template <typename ContextClass>
	int ContextHandler<ContextClass>::context_count = 0;

	template <typename ContextClass> ContextHandler<ContextClass>::ContextHandler(ContextCode context_code, int maj, int min) {
		std::cout << "INIT " << ContextHandler::context_count << std::endl;
		if (ContextHandler::context_count > 0) {
			throw DSightBaseException("Multiple Context.", DSIGHT_EXCEPTION_MULTIPLE_CONTEXT);
		}
		else {
			ContextHandler::context_count += 1;
			switch (context_code) {
				#ifdef _USE_GLFW3_
				case DSIGHT_CONTEXT_GLFW3:
					//m_wrapper = ContextGLFW3();
					break;
				#endif
				default:
					std::cout << "NEVER\n"; 
					ContextHandler::context_count = 0;
					throw DSightBaseException("Unsupported Context", DSIGHT_EXCEPTION_UNSUPPORTED_CONTEXT);
			}
		}
		std::cout << "INIT END " << ContextHandler::context_count << std::endl;
	}
}
