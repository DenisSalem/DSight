#include "Contexts/ContextCodes.hpp"
#include "Contexts/ContextHandler.hpp"
#include "Exceptions/ExceptionCodes.hpp"
#include "Exceptions/DSightBaseException.hpp"
#include <assert.h>

using namespace DSight;

template <typename ContextType> bool DestructorResetStates(ContextCode context_code) {
	try {
		auto c1 = new ContextHandler<ContextType>(context_code, 3,3);
		delete c1;
		auto c2 = new ContextHandler<ContextType>(context_code, 3,3);
		delete c2;
	}
	catch (const DSightBaseException& e) {
		if (e.code == DSIGHT_EXCEPTION_MULTIPLE_CONTEXT) {
			return 0;
		}
		throw;
	}
	return 1;
}


template <typename ContextType> bool SingleContextHandlerInstance(ContextCode context_code) {
	try {
		ContextHandler<ContextType> context(context_code, 3, 3);
		ContextHandler<ContextType> context2(context_code, 3, 3);
  	}
	catch (const DSightBaseException& e) {
		if (e.code == DSIGHT_EXCEPTION_MULTIPLE_CONTEXT) {
			return 1;
		}
		throw;
	}
	catch (...) {}
	return 0;
}

int main() {
	assert(SingleContextHandlerInstance<ContextGLFW3>(DSIGHT_CONTEXT_GLFW3));
	assert(DestructorResetStates<ContextGLFW3>(DSIGHT_CONTEXT_GLFW3));
	return 0;
}
