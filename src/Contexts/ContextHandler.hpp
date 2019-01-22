#ifndef _DSIGHT_CONTEXT_HANDLER_HPP_INCLUDED_
#define _DSIGHT_CONTEXT_HANDLER_HPP_INCLUDED_

#include "../Charts/HistogramCPU.hpp"
#include "../Canvas/Canvas.hpp"

#ifdef _USE_GLFW3_
#include "../Charts/HistogramGL.hpp"
#endif

#include "ContextCodes.hpp"

#ifdef _USE_GLFW3_
#include "ContextGLFW3.hpp"
#endif

namespace DSight {
	template <typename ContextClass> class ContextHandler {
		public:
			ContextHandler(ContextCode context_code, int maj, int min);
			~ContextHandler();
			
			Canvas * AddCanvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision);
			Histogram * AddHistogram(unsigned int canvas_index);
			Histogram * AddHistogram(unsigned int canvas_index, unsigned int viewport_id);
			
		private:
			ContextCode m_context_code;
			ContextClass * m_wrapper;
			std::vector<Canvas> m_canvas;
			static int context_count;
			void SetDesignerCallback();
	};
}

#endif
