#include "DSightBaseException.hpp"

namespace DSight {
	DSightBaseException::DSightBaseException(const char * message, ExceptionCode code) {
		this->message = message;
		this->code = code;
	}

	const char* DSightBaseException::what() const noexcept {
		return this->message;
	}
}
