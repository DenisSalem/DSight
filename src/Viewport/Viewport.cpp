#include <sys/time.h>

#include "../Macros.hpp"
#include "Viewport.hpp"

namespace DSight {
	Viewport::Viewport(Area a) : area(a) {
		DSIGHT_SET_UNIQUE_IDENTIFIER(m_identifier);
	}
	
	Histogram * Viewport::SetHistogram() {
		//~ switch (m_context_code) {
			//~ case ContextCode::GLFW3:
				//~ return new DSight::HistogramGL();
				//~ break;
			//~ default:
				//~ return new DSight::HistogramCPU();
		//~ }
		return NULL;
	}
	
	bool operator== (const Viewport &v1, const Viewport &v2) {
		return v1.m_identifier == v2.m_identifier;
	}
	
}
