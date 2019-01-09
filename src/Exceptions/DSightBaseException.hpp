#include <exception>
#include "ExceptionCodes.hpp"

namespace DSight {
	class DSightBaseException: public std::exception {
		public:
			DSightBaseException(const char * message, ExceptionCode code);
			virtual const char* what() const noexcept;
			const char * message;
			ExceptionCode code;
	};
}
