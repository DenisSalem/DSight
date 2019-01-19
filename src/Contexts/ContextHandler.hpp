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
			~ContextHandler();
			void LoopRender();
			void SetDesignerCallback();
			
		protected:
			ContextClass * m_wrapper;
			static int context_count;
	};
}
