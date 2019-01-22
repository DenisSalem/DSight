#include "Viewport.hpp"

namespace DSight {
	Viewport::Viewport(Area a) : area(a) {}
	
	Histogram * Viewport::SetHistogram() {
		switch (m_context_code) {
			case DSIGHT_CONTEXT_GLFW3:
				return new DSight::HistogramGL();
				break;
			default:
				return new DSight::HistogramCPU();
		}
	}
}
