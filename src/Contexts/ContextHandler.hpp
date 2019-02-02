#ifndef DSIGHT_CONTEXT_HANDLER_HPP_INCLUDED
#define DSIGHT_CONTEXT_HANDLER_HPP_INCLUDED
#include <thread>
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
			ContextHandler& SetDefaultCanvasSize(int default_width, int default_height);
			friend bool operator== (const ContextHandler &c1, const ContextHandler &c2);
			
			bool static IsContextUsesGL();
			bool static IsCanvasInstantiationAllowed();
			long int static GetCurrentContextIdentifier();
			void static Draw();
			
		private:
			ContextCode m_context_code;
			ContextBase * m_backend;
			std::vector<Canvas * > m_canvas;
			std::vector<std::thread * > m_canvas_threads;
			long int m_identifier;
			int m_default_width;
			int m_default_height;
			std::thread * m_main_thread;

			static bool canvas_instantiation_allowed;
			static int context_count;
			static bool gl_enabled;
			static ContextHandler * context_handler;
			static long int static_identifier;
	};
}

#endif
