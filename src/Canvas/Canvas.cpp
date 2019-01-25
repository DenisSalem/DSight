#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/BaseException.hpp"
#include "Canvas.hpp"

namespace DSight {
	Canvas::Canvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision)
	: m_horizontal_subdivision(horizontal_subdivision), m_vertical_subdivision(vertical_subdivision) {}
	
	Canvas::~Canvas() {
		for (unsigned int i = 0; i < m_viewports.size(); i++) {
			delete m_viewports[i];
		} 
	}
	
	Viewport * Canvas::AddViewport(unsigned int tl_x, unsigned int tl_y, unsigned int br_x, unsigned int br_y) {
		Area area = {
			tl_x,
			tl_y,
			br_x,
			br_y
		};
		
		// TEST IF NOT OUT OF BOUND
		if (tl_x >= m_horizontal_subdivision || br_x >= m_horizontal_subdivision || tl_y >= m_vertical_subdivision || br_y >= m_vertical_subdivision) {
			throw DSight::BaseException("Invalid Coordinates.", ExceptionCode::INVALID_COORDINATES);
		}
		// TEST IF WELL FORMED
		if(tl_x > br_x || tl_y > br_y) {
			throw DSight::BaseException("Invalid Coordinates.", ExceptionCode::INVALID_COORDINATES);
		}

		if (Overlap(area)) {
			throw DSight::BaseException("Invalid Coordinates.", ExceptionCode::INVALID_COORDINATES);
		}
		m_viewports.push_back(
			new Viewport(area)
		);
		return m_viewports.back();
	}
	
	bool Canvas::Overlap(Area area) {
		for (unsigned int i =0; i < m_viewports.size(); i++) {
			// If one rectangle is on left side of other 
			if (area.tl_x > m_viewports[i]->area.br_x || m_viewports[i]->area.tl_x > area.br_x) 
				return false; 
  
			// If one rectangle is above other 
			if (area.tl_y > m_viewports[i]->area.br_y || m_viewports[i]->area.tl_y > area.br_y) 
				return false; 
		}
		return true;
	}
}
