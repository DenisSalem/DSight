#include <vector>

namespace DSight {
	class ContextBase {
		public:
			virtual void CreateCanvas(const char * canvas_name) = 0;
			virtual void DeleteCanvas(unsigned int index) = 0;
			int m_default_width;
			int m_default_height;
	};
}
