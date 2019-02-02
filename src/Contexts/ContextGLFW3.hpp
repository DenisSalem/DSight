#include <GLFW/glfw3.h>
#include "../Canvas/Canvas.hpp"
#include "ContextBase.hpp"

namespace DSight {
	class ContextGLFW3 final: public ContextBase {
		public:
			ContextGLFW3(int maj, int min, int default_width, int default_height);
			~ContextGLFW3();
			void LoopRender(void * backend_canvas, Canvas * canvas);
			void CreateCanvas(const char * canvas_name);
			void DeleteCanvas(unsigned int index);
			void * GetCanvas(unsigned int index);
			int m_default_width;
			int m_default_height;
		
		private:
			std::vector<GLFWwindow*> m_windows;

	};
}
