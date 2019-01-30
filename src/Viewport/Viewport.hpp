#ifndef DSIGHT_VIEWPORT_HPP_INCLUDED
#define DSIGHT_VIEWPORT_HPP_INCLUDED

#include "../Charts/Histogram.hpp"
#include "../Contexts/ContextCodes.hpp"
#include "../Area.hpp"

namespace DSight {	
	class Viewport {
		public:
			Viewport(Area a);
			~Viewport();
			Area area;
			Histogram& SetHistogram();
			friend bool operator== (const Viewport &v1, const Viewport &v2);

		private:
			Chart * m_chart;
			ChartType m_chart_type;
			ContextCode m_context_code;
			long int m_identifier;

	};
}

#endif
