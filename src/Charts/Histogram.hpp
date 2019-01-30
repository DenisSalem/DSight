#ifndef DSIGHT_HISTOGRAM_HPP_INCLUDED
#define DSIGHT_HISTOGRAM_HPP_INCLUDED

#include <utility>
#include <vector>
#include <iostream>
#include "Chart.hpp"
#include "HistogramBackend.hpp"

namespace DSight {
	class Histogram final : public Chart {
		public:
			Histogram();
			~Histogram();
			void SetPair(std::vector<float> * values, std::vector<float> * frequencies);
			void SetPair(std::vector<std::pair<float, float>> * pair_values_frequencies);
			void Draw();
			
		protected:
			HistogramBackend * m_backend;
			std::vector< std::pair<float, float>> * m_pair_values_frequencies;
	};
}

#endif
