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

int main() {
	assert(DirectInstantiationForbidden());
	return 0;
}
