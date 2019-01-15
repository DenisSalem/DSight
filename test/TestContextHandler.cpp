#include "Contexts/ContextCodes.hpp"
#include "Contexts/ContextHandler.hpp"
#include "Exceptions/ExceptionCodes.hpp"
#include "Exceptions/DSightBaseException.hpp"
#include <assert.h>

using namespace DSight;

template <typename ContextType> bool SingleContextHandlerInstance() {
	try {
		ContextHandler<ContextType> context(DSIGHT_CONTEXT_GLFW3, 0, 0);
		ContextHandler<ContextType> context2(DSIGHT_CONTEXT_GLFW3, 1, 0);
  	}
	catch (const DSightBaseException& e) {
		if (e.code == DSIGHT_EXCEPTION_MULTIPLE_CONTEXT) {
			return 1;
		}
	}
	catch (...) {}
	return 0;
}

int main(int argc, char ** argv) {
	assert(SingleContextHandlerInstance<ContextGLFW3>());
	return 0;
}
