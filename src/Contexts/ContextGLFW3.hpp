#include <GLFW/glfw3.h>
#include <vector>

namespace DSight {
	class ContextGLFW3 {
		public:
			ContextGLFW3();
			
		private:
			std::vector<GLFWwindow*> m_surfaces;
	};
}
