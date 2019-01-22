#ifndef DSIGHT_VIEWPORT_HPP_INCLUDED
#define DSIGHT_VIEWPORT_HPP_INCLUDED

#ifdef _USE_GLFW3_
#include "../Charts/HistogramGL.hpp"
#endif

#include "../Charts/HistogramCPU.hpp"
#include "../Contexts/ContextCodes.hpp"
#include "../Area.hpp"

namespace DSight {
	class Viewport {
		public:
			Viewport(Area a);
			Area area;
			Histogram * SetHistogram();
			
		private:
			ContextCode m_context_code;
	};
}

#endif
