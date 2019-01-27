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
		canvas.AddViewport(0,0,4,4);
	}
	catch (DSight::BaseException &e) {
		if (e.code == DSight::ExceptionCode::INVALID_COORDINATES_OUT_OF_BOUNDS) {
			return 1;
		}
		throw;
	}
	return 0; 
}

bool DoNotOverlap(DSight::ContextCode context_code) {
	DSight::ContextHandler context(context_code, 3,3);
	DSight::Canvas& canvas = context.AddCanvas(4,4);
	canvas.AddViewport(0,0,2,2);
	try {
		canvas.AddViewport(2,2,5,5);

	} catch(DSight::BaseException &e) {
		if (e.code == DSight::ExceptionCode::INVALID_COORDINATES_OVERLAP) {
			return 0;
		}
		throw;	
	}
	return 1;
}

bool PreventViewportOverlap(DSight::ContextCode context_code) {
	DSight::ContextHandler context(context_code, 3,3);
	DSight::Canvas& canvas = context.AddCanvas(4,4);
	canvas.AddViewport(0,0,2,2);
	try {
		canvas.AddViewport(1,1,3,3);

	} catch(DSight::BaseException &e) {
		if (e.code == DSight::ExceptionCode::INVALID_COORDINATES_OVERLAP) {
			return 1;
		}
		throw;	
	}
	return 0;
}

bool PreventViewportOverlapFromZeroZeroToOneOne(DSight::ContextCode context_code) {
	DSight::ContextHandler context(context_code, 3,3);
	DSight::Canvas& canvas = context.AddCanvas(2,2);
	canvas.AddViewport(0,0,1,1);
	try {
		canvas.AddViewport(0,0,1,1);

	} catch(DSight::BaseException &e) {
		if (e.code == DSight::ExceptionCode::INVALID_COORDINATES_OVERLAP) {
			return 1;
		}
		throw;	
	}
	return 0;
}

bool ZeroSubdivision(DSight::ContextCode context_code)  {
	DSight::ContextHandler context(context_code, 3,3);
	DSight::Canvas& canvas = context.AddCanvas(0,0);
	try {
		canvas.AddViewport(0,0,1,1);
	} catch(DSight::BaseException &e) {
		if (e.code == DSight::ExceptionCode::INVALID_COORDINATES_OUT_OF_BOUNDS) {
			return 0;
		}
		throw;	
	}
	return 1;
}

int main() {
	assert(DirectInstantiationForbidden());
	#ifdef _USE_GLFW3_
	assert(AddOutOfBoundViewport(DSight::ContextCode::GLFW3));
	assert(PreventViewportOverlap(DSight::ContextCode::GLFW3));
	assert(PreventViewportOverlapFromZeroZeroToOneOne(DSight::ContextCode::GLFW3));
	assert(DoNotOverlap(DSight::ContextCode::GLFW3));
	assert(ZeroSubdivision(DSight::ContextCode::GLFW3));
	#endif
	return 0;
}

