#include "Histogram.hpp"

namespace DSight {
	class HistogramCPU : public Histogram {
		public:
			SetPair(std::vector<float> values, std::vector<float> frequencies);
			SetPair(std::vector<std::pair<float, float>> pair_values_frequencies);
			void Draw();
			
		protected:
			std::vector<std::pair<float, float>> * pair_values_frequencies;
	}
}
