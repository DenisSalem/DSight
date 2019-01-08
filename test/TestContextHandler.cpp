#include "Contexts/ContextHandler.hpp"
#include "Exceptions/ExceptionCodes.hpp"
#include "Exceptions/DSightBaseException.hpp"
#include <iostream>
#include <assert.h>

bool SingleContextHandlerInstance() {
	try {
		ContextHandler context(DSIGHT_GLFW3_CONTEXT);
		ContextHandler context2(DSIGHT_GLFW3_CONTEXT);
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
	assert (SingleContextHandlerInstance());
	return 0;
}
