#include <sys/time.h>
#include "../Macros.hpp"
#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/ExceptionMessages.hpp"
#include "../Exceptions/BaseException.hpp"
#include "../Contexts/ContextHandler.hpp"
#include "Canvas.hpp"

namespace DSight {
	bool Canvas::viewport_instantiation_allowed = 0;

	Canvas::Canvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision)
	: m_horizontal_subdivision(horizontal_subdivision), m_vertical_subdivision(vertical_subdivision)
	{
		if (!ContextHandler::IsCanvasInstantiationAllowed()) {
			throw BaseException(DSIGHT_MSG_INSTANTIATION_ERROR, DSight::ExceptionCode::INSTANTIATION_ERROR);
		}
		DSIGHT_SET_UNIQUE_IDENTIFIER(m_identifier);
	}
	
	Canvas::~Canvas() {
		for (unsigned int i = 0; i < m_viewports.size(); i++) {
			delete m_viewports[i];
		} 
		Canvas::viewport_instantiation_allowed = 0;
	}
	
	Viewport& Canvas::AddViewport(unsigned int tl_x, unsigned int tl_y, unsigned int br_x, unsigned int br_y) {
		Area area = {
			tl_x,
			tl_y,
			br_x,
			br_y
		};
		
		// TEST IF NOT OUT OF BOUND
		if (tl_x > m_horizontal_subdivision || br_x > m_horizontal_subdivision+1 || tl_y > m_vertical_subdivision || br_y > m_vertical_subdivision+1) {
			throw DSight::BaseException(DSIGHT_MSG_INVALID_COORDINATES_OUT_OF_BOUNDS, ExceptionCode::INVALID_COORDINATES_OUT_OF_BOUNDS);
		}
		// TEST IF WELL FORMED
		if(tl_x > br_x || tl_y > br_y) {
			throw DSight::BaseException(DSIGHT_MSG_INVALID_COORDINATES, ExceptionCode::INVALID_COORDINATES);
		}

		if (Overlap(area)) {
			throw DSight::BaseException(DSIGHT_MSG_INVALID_COORDINATES_OVERLAP, ExceptionCode::INVALID_COORDINATES_OVERLAP);
		}
		Canvas::viewport_instantiation_allowed = 1;
		m_viewports.push_back(
			new Viewport(area)
		);
		Canvas::viewport_instantiation_allowed = 0;
		return *(m_viewports.back());
	}
	
	bool Canvas::RemoveViewport(Viewport& viewport) {
		for (unsigned int i = 0; i < m_viewports.size(); i++) {
			if ( *(m_viewports[i]) == viewport) {
				delete m_viewports[i];
				m_viewports.erase(m_viewports.begin() + i);
				return 1;
			}
		}
		return 0;
	}

	bool Canvas::Overlap(Area area) {
		if (m_viewports.size() == 0) {
			return 0;
		}
		bool overlap = true;
		for (unsigned int i =0; i < m_viewports.size(); i++) {
			overlap = true;
			// If one rectangle is on left side of other 
			if (area.tl_x >= m_viewports[i]->area.br_x || m_viewports[i]->area.tl_x >= area.br_x) 
				overlap = false; 
  
			// If one rectangle is above other 
			if (area.tl_y >= m_viewports[i]->area.br_y || m_viewports[i]->area.tl_y >= area.br_y) 
				overlap = false;
			}
			
			if (overlap) {
				return true;
			}
			
		return 0;
	}
	
	bool operator== (const Canvas &c1, const Canvas &c2) {
		return c1.m_identifier == c2.m_identifier;
	}
}
