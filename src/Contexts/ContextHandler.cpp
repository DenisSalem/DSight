#include <sys/time.h>

#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/BaseException.hpp"
#include "../Exceptions/ExceptionMessages.hpp"
#include "ContextHandler.hpp"

namespace DSight {
	int ContextHandler::context_count = 0;
	long int ContextHandler::static_identifier = 0;
	bool ContextHandler::canvas_instantiation_allowed = 0;
	bool ContextHandler::gl_enabled = false;
	ContextHandler * ContextHandler::context_handler = NULL;

	ContextHandler::ContextHandler(ContextCode context_code, int maj, int min) : m_context_code(context_code), m_default_width(640), m_default_height(480) {
		struct timeval tp;
		gettimeofday(&tp, NULL);
		m_identifier = tp.tv_sec * 1000 + tp.tv_usec / 1000;
		static_identifier = m_identifier;
		if (ContextHandler::context_count > 0) {
			throw DSight::BaseException(DSIGHT_MSG_MULTIPLE_CONTEXT, ExceptionCode::MULTIPLE_CONTEXT);
		}
		else {
			ContextHandler::context_count += 1;
			switch (context_code) {
				#ifdef _USE_GLFW3_
				case ContextCode::GLFW3:
					m_backend = new DSight::ContextGLFW3(maj, min, m_default_width, m_default_height);
					gl_enabled = true;
					break;
				#endif
				default:
					ContextHandler::context_count = 0;
					throw DSight::BaseException(DSIGHT_MSG_UNSUPPORTED_CONTEXT, ExceptionCode::UNSUPPORTED_CONTEXT);
			}
		}
		ContextHandler::context_handler = this;
	}
	
	long int ContextHandler::GetCurrentContextIdentifier() {
		return static_identifier;
	}
	
	bool ContextHandler::IsCanvasInstantiationAllowed() {
		return canvas_instantiation_allowed;
	}
	
	bool ContextHandler::IsContextUsesGL() {
		return gl_enabled;
	}
	
	void ContextHandler::Draw() {
		printf("Static ContextHandler Draw()\n");
	}
		
	Canvas& ContextHandler::AddCanvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision, const char * canvas_name) {
		canvas_instantiation_allowed = 1;
		m_backend->CreateCanvas(canvas_name);
		m_canvas.push_back(
			new Canvas(horizontal_subdivision, vertical_subdivision)
		);
		canvas_instantiation_allowed = 0;
		return *(m_canvas.back());
		
	}
	
	bool ContextHandler::RemoveCanvas(Canvas& canvas) {
		for (unsigned int i = 0; i < m_canvas.size(); i++) {
			if ( *(m_canvas[i]) == canvas) {
				delete m_canvas[i];
				m_canvas.erase(m_canvas.begin() + i);
				m_backend->DeleteCanvas(i);
				return 1;
			}
		}
		return 0;
	}
	
	ContextHandler::~ContextHandler() {
		for (unsigned int i = 0; i< m_canvas.size(); i++) {
			delete m_canvas[i];
		}
		
		switch (m_context_code) {
			case ContextCode::GLFW3:
				delete (ContextGLFW3 *) m_backend;
				break;
				
			default:
				break;
		}
		
		ContextHandler::context_count = 0;
		ContextHandler::static_identifier = 0;
		ContextHandler::context_handler = NULL;
	}
	
	ContextHandler& ContextHandler::SetDefaultCanvasSize(int default_width, int default_height) {
		m_default_width = default_width;
		m_default_height = default_height;
		m_backend->m_default_width = default_width;
		m_backend->m_default_height = default_height;
		return *this;
	}

	bool operator== (const ContextHandler &c1, const ContextHandler &c2) {
		return c1.m_identifier == c2.m_identifier;
	}
}
