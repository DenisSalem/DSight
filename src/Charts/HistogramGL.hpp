#ifndef DSIGHT_HISTOGRAM_GL_HPP_INCLUDED
#define DSIGHT_HISTOGRAM_GL_HPP_INCLUDED

#include "HistogramBackend.hpp"

namespace DSight {
	class HistogramGL final: public HistogramBackend {
		public:
			void Draw();			
	};
}

#endif
