#include <sys/time.h>

#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/BaseException.hpp"
#include "../Exceptions/ExceptionMessages.hpp"
#include "ContextHandler.hpp"

namespace DSight {
	int ContextHandler::context_count = 0;
	long int ContextHandler::context_identifier = 0;
	bool ContextHandler::canvas_instantiation_allowed = 0;

	ContextHandler::ContextHandler(ContextCode context_code, int maj, int min) : m_context_code(context_code) {
		struct timeval tp;
		gettimeofday(&tp, NULL);
		ContextHandler::context_identifier = tp.tv_sec * 1000 + tp.tv_usec / 1000;
		
		if (ContextHandler::context_count > 0) {
			throw DSight::BaseException(DSIGHT_MSG_MULTIPLE_CONTEXT, ExceptionCode::MULTIPLE_CONTEXT);
		}
		else {
			ContextHandler::context_count += 1;
			switch (context_code) {
				#ifdef _USE_GLFW3_
				case ContextCode::GLFW3:
					m_wrapper = new DSight::ContextGLFW3(maj, min);
					break;
				#endif
				default:
					ContextHandler::context_count = 0;
					throw DSight::BaseException(DSIGHT_MSG_UNSUPPORTED_CONTEXT, ExceptionCode::UNSUPPORTED_CONTEXT);
			}
		}
	}
	
	long int ContextHandler::GetCurrentContextIdentifier() {
		return ContextHandler::context_identifier;
	}
	
	bool ContextHandler::IsCanvasInstantiationAllowed() {
		return canvas_instantiation_allowed;
	}
	
	Canvas& ContextHandler::AddCanvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision) {
		canvas_instantiation_allowed = 1;
		m_wrapper->CreateCanvas();
		m_canvas.push_back(
			new Canvas(horizontal_subdivision, vertical_subdivision)
		);
		canvas_instantiation_allowed = 0;
		return *(m_canvas.back());
		
	}
	
	ContextHandler::~ContextHandler() {
		for (unsigned int i = 0; i< m_canvas.size(); i++) {
			delete m_canvas[i];
		}
		
		switch (m_context_code) {
			case ContextCode::GLFW3:
				delete (ContextGLFW3 *) m_wrapper;
				break;
				
			default:
				break;
		}
		
		ContextHandler::context_count = 0;
		ContextHandler::context_identifier = 0;
	}
}
