#include <exception>
#include <iostream>
#include "ContextCodes.hpp"
#ifdef _USE_GLFW3_
#include "ContextGLFW3.hpp"
#endif
namespace DSight {
	template <typename ContextClass> class ContextHandler {
		public:
			ContextHandler(ContextCode context_code, int maj, int min);

		protected:
			ContextClass m_wrapper;
			static int context_count;
	};
	
	#ifdef _USE_GLFW3_
	template class ContextHandler<ContextGLFW3>;
	#endif
}
