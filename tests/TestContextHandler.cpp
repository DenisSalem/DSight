#include "Contexts/ContextCodes.hpp"
#include "Contexts/ContextHandler.hpp"
#include "Exceptions/ExceptionCodes.hpp"
#include "Exceptions/DSightBaseException.hpp"
#include <assert.h>

using namespace DSight;

bool DestructorResetStates(ContextCode context_code) {
	try {
		auto c1 = new ContextHandler(context_code, 3,3);
		delete c1;
		auto c2 = new ContextHandler(context_code, 3,3);
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


bool SingleContextHandlerInstance(ContextCode context_code) {
	try {
		ContextHandler context(context_code, 3, 3);
		ContextHandler context2(context_code, 3, 3);
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
	assert(SingleContextHandlerInstance(DSIGHT_CONTEXT_GLFW3));
	assert(DestructorResetStates(DSIGHT_CONTEXT_GLFW3));
	return 0;
}
