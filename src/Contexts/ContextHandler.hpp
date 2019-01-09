#include <exception>
#include <iostream>
#include "ContextCodes.hpp"
#include "ContextWrapper.hpp"

namespace DSight {
	class ContextHandler {
		public:
			ContextHandler(ContextCode context_code);

		protected:
			static int context_count;
	};
}
