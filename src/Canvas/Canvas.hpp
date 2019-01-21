#include "../Contexts/ContextHandler.hpp"

namespace DSight {
	class Canvas {
		public:
			ViewPort * AddViewport();
			
		private:
			unsigned int canvas_index;
			ContextHandler<ContextType> * context_handler;
	}
}
