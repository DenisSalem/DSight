#include <vector>

namespace DSight {
	class Chart {
		public:
			void SetRefreshDataCallback(void (*refresh_data_callback)(Chart *, void *));
			
			virtual void Draw() = 0;
			virtual void SetPair(std::vector<float> * a, std::vector<float> * b) = 0;
			virtual void SetPair(std::vector<std::pair<float, float>> * p) = 0;
			
		protected:
			void (*m_refresh_data_callback)(Chart *, void *);
			void * refresh_data_callback_args;
	};
}
