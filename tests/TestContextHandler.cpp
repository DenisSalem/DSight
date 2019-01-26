#include "Contexts/ContextCodes.hpp"
#include "Contexts/ContextHandler.hpp"
#include "Exceptions/ExceptionCodes.hpp"
#include "Exceptions/BaseException.hpp"
#include <assert.h>

bool DestructorResetStates(DSight::ContextCode context_code) {
	try {
		auto c1 = new DSight::ContextHandler(context_code, 3,3);
		delete c1;
		auto c2 = new DSight::ContextHandler(context_code, 3,3);
		delete c2;
	}
	catch (const DSight::BaseException& e) {
		if (e.code == DSight::ExceptionCode::MULTIPLE_CONTEXT) {
			return 0;
		}
		throw;
	}
	return 1;
}


bool SingleContextHandlerInstance(DSight::ContextCode context_code) {
	try {
		DSight::ContextHandler context(context_code, 3, 3);
		DSight::ContextHandler context2(context_code, 3, 3);
  	}
	catch (const DSight::BaseException& e) {
		if (e.code == DSight::ExceptionCode::MULTIPLE_CONTEXT) {
			return 1;
		}
		throw;
	}
	return 0;
}

int main() {
	#ifdef _USE_GLFW3_
	assert(SingleContextHandlerInstance(DSight::ContextCode::GLFW3));
	assert(DestructorResetStates(DSight::ContextCode::GLFW3));
	#endif
	return 0;
}
