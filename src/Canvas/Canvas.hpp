#ifndef _DSIGHT_CANVAS_HPP_INCLUDED_
#define _DSIGHT_CANVAS_HPP_INCLUDED_

#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/DSightBaseException.hpp"
#include "../Contexts/ContextHandler.hpp"
#include "../Viewport/Viewport.hpp"

namespace DSight {
	struct Area{
		unsigned int tl;
		unsigned int br;
	};
	
	class Canvas {
		public:
			Canvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision);			
			Viewport * AddViewport();
			
		private:
			bool Overlap(Area new_area);
			unsigned int m_horizontal_subdivision;
			unsigned int m_vertical_subdivision;
			unsigned int m_canvas_index;
			std::vector<Viewport> m_viewports;
			ContextHandler<ContextType> * m_context_handler;
	};
}

#endif
