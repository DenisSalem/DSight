#include <sys/time.h>

#include "../Macros.hpp"
#include "Viewport.hpp"

namespace DSight {
	Viewport::Viewport(Area a) : area(a) {
		DSIGHT_SET_UNIQUE_IDENTIFIER(m_identifier);
	}
	
	Viewport::~Viewport() {
		switch (m_chart_type) {
			case ChartType::HISTOGRAM:
				delete (Histogram*) m_chart;
				break;
		}
	}
	
	Histogram& Viewport::SetHistogram() {
		m_chart = new DSight::Histogram();
		m_chart_type = ChartType::HISTOGRAM;
		return (Histogram&) *m_chart;
	}
	
	bool operator== (const Viewport &v1, const Viewport &v2) {
		return v1.m_identifier == v2.m_identifier;
	}
	
}
