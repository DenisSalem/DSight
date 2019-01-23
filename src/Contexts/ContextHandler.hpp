#ifndef DSIGHT_CONTEXT_HANDLER_HPP_INCLUDED
#define DSIGHT_CONTEXT_HANDLER_HPP_INCLUDED

#include "../Canvas/Canvas.hpp"
#include "ContextCodes.hpp"

#ifdef _USE_GLFW3_
#include "ContextGLFW3.hpp"
#endif

namespace DSight {
	class ContextHandler {
		public:
			ContextHandler(ContextCode context_code, int maj, int min);
			~ContextHandler();
			
			Canvas * AddCanvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision);
			
		private:
			ContextCode m_context_code;
			ContextBase * m_wrapper;
			std::vector<Canvas *> m_canvas;
			static int context_count;
	};
}

#endif
