#ifndef _DSIGHT_CANVAS_HPP_INCLUDED_
#define _DSIGHT_CANVAS_HPP_INCLUDED_
#include <thread>
#include "../Area.hpp"
#include "../Viewport/Viewport.hpp"

namespace DSight {
	class Canvas {
		public:
			Canvas(unsigned int horizontal_subdivision, unsigned int vertical_subdivision);
			~Canvas();		
			Viewport& AddViewport(unsigned int tl_x, unsigned int tl_y, unsigned int br_x, unsigned int br_y);
			bool RemoveViewport(Viewport& viewport);
			friend bool operator== (const Canvas &c1, const Canvas &c2);
			void Draw();
			
		private:
			bool Overlap(Area new_area);
			unsigned int m_horizontal_subdivision;
			long int m_identifier;
			unsigned int m_vertical_subdivision;
			std::vector<Viewport * > m_viewports;
			static bool viewport_instantiation_allowed;
	};
}

#endif
