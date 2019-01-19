#include <utility>
#include <vector>

namespace DSight {
	class Histogram {
		public:
			~Histogram();
			SetPair(std::vector<float> values, std::vector<float> frequencies);
			SetPair(std::vector<std::pair<float, float>> pair_values_frequencies);
			virtual void Draw() = 0;
			
		protected:
			std::vector<float, float> m_pair_values_frequencies;
	}
}
