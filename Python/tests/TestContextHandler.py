#! /usr/bin/python3

import dsight

def SingleContextHandlerInstance(context_code):
	try:
		c = dsight.ContextHandler(context_code,3,3)
		c = dsight.ContextHandler(context_code,3,3)

	except dsight.PythonExceptionWrapper as e:
		message, code = e.args
		if code == dsight.EXCEPTION_CODE_MULTIPLE_CONTEXT:
			return True
			
	return False
def DestructorResetStates(context_code):
	try:
		c1 = dsight.ContextHandler(context_code,3,3)
		c1 = None
		c2 = dsight.ContextHandler(context_code,3,3)

	except dsight.PythonExceptionWrapper as e:
		message, code = e.args
		if code == dsight.EXCEPTION_CODE_MULTIPLE_CONTEXT:
			return False
		raise e
		
	return True
	
assert(SingleContextHandlerInstance(dsight.CONTEXT_CODE_GLFW3))
assert(DestructorResetStates(dsight.CONTEXT_CODE_GLFW3));
