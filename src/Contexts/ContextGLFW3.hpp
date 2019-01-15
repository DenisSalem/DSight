#include <GLFW/glfw3.h>
#include "ContextBase.hpp"

namespace DSight {
	class ContextGLFW3 : ContextBase {
		public:
			ContextGLFW3();
			~ContextGLFW3();
			void TestDisplayWindow();
		
		protected:
			int CreateSurface();
			void DeleteSurface(int index);

	};
}
