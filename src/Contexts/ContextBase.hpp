#include <vector>

namespace DSight {
	class ContextBase {
		protected:
			virtual void CreateCanvas() = 0;
			virtual void DeleteCanvas(unsigned int index) = 0;
	};
}
