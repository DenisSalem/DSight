#include "Contexts/ContextCodes.hpp"
#include "Contexts/ContextHandler.hpp"
#include "Exceptions/ExceptionCodes.hpp"
#include "Exceptions/BaseException.hpp"
#include <assert.h>

bool DirectInstantiationForbidden() {
	try{
		DSight::Canvas canvas(1,1);
	}
	catch(DSight::BaseException &e) {
		if (e.code == DSight::ExceptionCode::INSTANTIATION_ERROR) {
			return 1;
		}
		throw;
	}
	return 0;
}

bool AddOutOfBoundViewport(DSight::ContextCode context_code) {
	DSight::ContextHandler context(context_code, 3,3);
	DSight::Canvas& canvas = context.AddCanvas(2,2);
	try {
		canvas.AddViewport(0,0,2,2);
	}
	catch (DSight::BaseException &e) {
		if (e.code == DSight::ExceptionCode::INVALID_COORDINATES) {
			return 1;
		}
		throw;
	}
	return 0; 
}

int main() {
	assert(DirectInstantiationForbidden());
	#ifdef _USE_GLFW3_
	assert(AddOutOfBoundViewport(DSight::ContextCode::GLFW3));
	#endif
	return 0;
}
