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
			
			Canvas& AddCanvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision, const char * canvas_name);
			bool RemoveCanvas(Canvas& canvas);
			bool static IsCanvasInstantiationAllowed();
			long int static GetCurrentContextIdentifier();
			ContextHandler& SetDefaultCanvasSize(int default_width, int default_height);
			friend bool operator== (const ContextHandler &c1, const ContextHandler &c2);
		private:
			ContextCode m_context_code;
			ContextBase * m_wrapper;
			std::vector<Canvas * > m_canvas;
			static int context_count;
			static long int static_identifier;
			long int m_identifier;
			int m_default_width;
			int m_default_height;
			static bool canvas_instantiation_allowed;
	};
}

#endif
