#include <exception>
#include <iostream>
#include "ContextWrapper.hpp"

#define DSIGHT_GLFW3_CONTEXT	0x474c4633
#define DSIGHT_GTK2_CONTEXT	0x67746b32
#define DSIGHT_GTK3_CONTEXT	0x67746b33
#define DSIGHT_SDL1_CONTEXT	0x53444c31
#define DSIGHT_SDL2_CONTEXT	0x53444c32

class ContextHandler {
	public:
		ContextHandler(int context_type);

	protected:
		static int context_count;
};
