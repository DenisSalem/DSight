#include "Canvas.hpp"

namespace DSight {
	Canvas::Canvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision)
	: m_horizontal_subdivision(horizontal_subdivision), m_vertical_subdivision(vertical_subdivision) {}
	
	Viewport * Canvas::AddViewport(unsigned int tl_x, unsigned int tl_y, unsigned int br_x, unsigned int br_y) {
		if(tl_x > br_x || tl_y > br_y) {
			throw DSightBaseException("Invalid Coordinates.", DSIGHT_EXCEPTION_INVALID_COORDINATES);
		}
	}
}
