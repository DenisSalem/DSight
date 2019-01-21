#include "Histogram.hpp"

namespace DSight {
	class HistogramCPU : public Histogram {
		public:
			void SetPair(std::vector<float> * values, std::vector<float> * frequencies);
			void SetPair(std::vector<std::pair<float, float>> * pair_values_frequencies);
			void Draw();
			
		protected:
			std::vector<std::pair<float, float>> * pair_values_frequencies;
	};
}
