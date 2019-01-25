#include "BaseException.hpp"

namespace DSight {
	BaseException::BaseException(const char * message, ExceptionCode code) {
		this->message = std::string("DSight: ")+message;
		this->code = code;
	}

	const char* BaseException::what() const noexcept {
		return this->message.c_str();
	}
}
