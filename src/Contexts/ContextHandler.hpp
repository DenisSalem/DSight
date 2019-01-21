#include "../Charts/HistogramCPU.hpp"
#include "../Charts/HistogramGL.hpp"

#include "ContextCodes.hpp"

#ifdef _USE_GLFW3_
#include "ContextGLFW3.hpp"
#endif

namespace DSight {
	template <typename ContextClass> class ContextHandler {
		public:
			ContextHandler(ContextCode context_code, int maj, int min);
			~ContextHandler();
			
			DSight::Canvas * AddCanvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision);
			void AddViewport(unsigned int canvas_index, unsigned int x, unsigned int y, unsigned int width, unsigned hint height);
			DSight::Histogram * AddHistogram(unsigned int canvas_index);
			DSight::Histogram * AddHistogram(unsigned int canvas_index, unsigned int viewport_id);
			
		private:
			ContextCode m_context_code;
			std::vector<unsigned char> grid;
			ContextClass * m_wrapper;
			static int context_count;
			void SetDesignerCallback();
	};
}
