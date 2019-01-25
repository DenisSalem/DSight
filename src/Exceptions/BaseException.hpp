#ifndef DSIGHT_BASE_EXCEPTION_HPP_INCLUDED
#define DSIGHT_BASE_EXCEPTION_HPP_INCLUDED

#include <string>
#include <exception>
#include "ExceptionCodes.hpp"

namespace DSight {
	class BaseException: public std::exception {
		public:
			BaseException(const char * message, ExceptionCode code);
			virtual const char* what() const noexcept;
			std::string message;
			ExceptionCode code;
	};
}

#endif
