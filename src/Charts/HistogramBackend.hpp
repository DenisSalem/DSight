#ifndef DSIGHT_HISTOGRAM_BACKEND_HPP_INCLUDED
#define DSIGHT_HISTOGRAM_BACKEND_HPP_INCLUDED

#include <utility>
#include <vector>
#include <iostream>

namespace DSight {
	class HistogramBackend {
		public:
			virtual void Draw() = 0;
	};
}

#endif
