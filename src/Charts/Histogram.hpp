#ifndef DSIGHT_HISTOGRAM_HPP_INCLUDED
#define DSIGHT_HISTOGRAM_HPP_INCLUDED

#include <utility>
#include <vector>
#include <iostream>

#include "Chart.hpp"

namespace DSight {
	class Histogram : public Chart {
		public:
			~Histogram();
			void SetPair(std::vector<float> * values, std::vector<float> * frequencies);
			void SetPair(std::vector<std::pair<float, float>> * pair_values_frequencies);
			virtual void Draw() = 0;
			
		protected:
			std::vector< std::pair<float, float>> * m_pair_values_frequencies;
	};
}

#endif
