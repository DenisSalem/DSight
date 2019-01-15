#include <string>
#include <exception>
#include "ExceptionCodes.hpp"

namespace DSight {
	class DSightBaseException: public std::exception {
		public:
			DSightBaseException(const char * message, ExceptionCode code);
			virtual const char* what() const noexcept;
			std::string message;
			ExceptionCode code;
	};
}
