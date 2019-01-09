#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/DSightBaseException.hpp"
#include "ContextHandler.hpp"

namespace DSight {
	int ContextHandler::context_count = 0;

	ContextHandler::ContextHandler(ContextCode context_code) {
		if (ContextHandler::context_count > 0) {
			throw DSightBaseException("Multiple Context", DSIGHT_EXCEPTION_MULTIPLE_CONTEXT);
		}
		else {
			/* Create Context */
			ContextHandler::context_count += 1;
		}
	}
}
