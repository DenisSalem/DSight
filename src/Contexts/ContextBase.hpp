#include <vector>

namespace DSight {
	class ContextBase {
		protected:
			virtual int CreateSurface() = 0;
			virtual void DeleteSurface(int index) = 0;
			std::vector<GLFWwindow*> m_surfaces;
	};
}
