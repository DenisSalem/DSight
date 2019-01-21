#ifndef _HISTOGRAM_HPP_INCLUDED_
#define _HISTOGRAM_HPP_INCLUDED_

#include <utility>
#include <vector>
#include <iostream>

namespace DSight {
	class Histogram {
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
