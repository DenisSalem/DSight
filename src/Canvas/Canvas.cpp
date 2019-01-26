#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/ExceptionMessages.hpp"
#include "../Exceptions/BaseException.hpp"
#include "../Contexts/ContextHandler.hpp"
#include "Canvas.hpp"

namespace DSight {
	Canvas::Canvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision)
	: m_horizontal_subdivision(horizontal_subdivision), m_vertical_subdivision(vertical_subdivision)
	{
		if (!ContextHandler::IsCanvasInstantiationAllowed()) {
			throw BaseException(DSIGHT_MSG_INSTANTIATION_ERROR, DSight::ExceptionCode::INSTANTIATION_ERROR);
		}
	}
	
	Canvas::~Canvas() {
		for (unsigned int i = 0; i < m_viewports.size(); i++) {
			delete m_viewports[i];
		} 
	}
	
	Viewport& Canvas::AddViewport(unsigned int tl_x, unsigned int tl_y, unsigned int br_x, unsigned int br_y) {
		Area area = {
			tl_x,
			tl_y,
			br_x,
			br_y
		};
		
		// TEST IF NOT OUT OF BOUND
		if (tl_x >= m_horizontal_subdivision || br_x > m_horizontal_subdivision || tl_y >= m_vertical_subdivision || br_y > m_vertical_subdivision) {
			throw DSight::BaseException(DSIGHT_MSG_INVALID_COORDINATES_OUT_OF_BOUNDS, ExceptionCode::INVALID_COORDINATES_OUT_OF_BOUNDS);
		}
		// TEST IF WELL FORMED
		if(tl_x > br_x || tl_y > br_y) {
			throw DSight::BaseException(DSIGHT_MSG_INVALID_COORDINATES, ExceptionCode::INVALID_COORDINATES);
		}

		if (Overlap(area)) {
			throw DSight::BaseException(DSIGHT_MSG_INVALID_COORDINATES_OVERLAP, ExceptionCode::INVALID_COORDINATES_OVERLAP);
		}
		m_viewports.push_back(
			new Viewport(area)
		);
		return *(m_viewports.back());
	}
	
	bool Canvas::Overlap(Area area) {
		if (m_viewports.size() == 0) {
			return 0;
		}
		for (unsigned int i =0; i < m_viewports.size(); i++) {
			// If one rectangle is on left side of other 
			if (area.tl_x >= m_viewports[i]->area.br_x || m_viewports[i]->area.tl_x >= area.br_x) 
				return 0; 
  
			// If one rectangle is above other 
			if (area.tl_y >= m_viewports[i]->area.br_y || m_viewports[i]->area.tl_y >= area.br_y) 
				return 0;
			}
		return 1;
	}
}
