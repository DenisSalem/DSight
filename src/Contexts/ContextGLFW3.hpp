#include <GLFW/glfw3.h>
#include "ContextBase.hpp"

namespace DSight {
	class ContextGLFW3 final: public ContextBase {
		public:
			ContextGLFW3(int maj, int min);
			~ContextGLFW3();
			void LoopRender();
			void CreateCanvas(const char * canvas_name);
			void DeleteCanvas(unsigned int index);
		
		private:
			std::vector<GLFWwindow*> m_windows;

	};
}
