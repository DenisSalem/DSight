#ifndef DSIGHT_HISTOGRAM_CPU_HPP_INCLUDED
#define DSIGHT_HISTOGRAM_CPU_HPP_INCLUDED

#include "HistogramBackend.hpp"

namespace DSight {
	class HistogramCPU final : public HistogramBackend {
		public:
			void Draw();
	};
}

#endif
