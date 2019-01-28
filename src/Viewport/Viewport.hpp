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
			friend bool operator== (const Viewport &v1, const Viewport &v2);

		private:
			ContextCode m_context_code;
			long int m_identifier;

	};
}

#endif
