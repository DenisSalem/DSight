#! /usr/bin/python3

import dsight

def SingleContextHandlerInstance(context_code):
	try:
		c = dsight.ContextHandler(context_code, 3, 3)
		c = dsight.ContextHandler(context_code, 3, 3)

	except dsight.DSightBaseException as e:
		return True
		
	return False

assert(SingleContextHandlerInstance(dsight.DSIGHT_CONTEXT_GLFW3))
