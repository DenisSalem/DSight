#! /usr/bin/python3
import sys
import dsight

def SingleContextHandlerInstance(context_code):
	try:
		c = dsight.ContextHandler(context_code,3,3)
		c = dsight.ContextHandler(context_code,3,3)

	except dsight.PythonExceptionWrapper as e:
		message, code = e.args
		if code == dsight.EXCEPTION_CODE_MULTIPLE_CONTEXT:
			return True
		
		raise e
			
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
	
def RemoveCanvas(context_code):
	context = dsight.ContextHandler(context_code, 3, 3)
	canvas = context.AddCanvas(0, 0, None)
	return context.RemoveCanvas(canvas)
	
def CannotRemoveCanvasViewportTwice(context_code):
	context = dsight.ContextHandler(context_code, 3, 3)
	canvas = context.AddCanvas(0, 0, None)
	context.RemoveCanvas(canvas)
	return not context.RemoveCanvas(canvas)

def SetDefaultCanvasSizeMustReturnItself(context_code):
	context = dsight.ContextHandler(context_code, 3, 3)
	return context == context.SetDefaultCanvasSize(100,100)

def ChainWhithSetDefaultCanvasSize(context_code):
	context = dsight.ContextHandler(context_code, 3, 3).SetDefaultCanvasSize(100,100)
	return type(context) == dsight.ContextHandler

def CheckRefCountChainWhithSetDefaultCanvasSize(context_code):	
	context = dsight.ContextHandler(context_code, 3, 3).SetDefaultCanvasSize(100,100)
	return sys.getrefcount(context) == 2

def CheckRefCountSetDefaultCanvasSize(context_code):	
	r1 = dsight.ContextHandler(context_code, 3, 3)
	r2 = r1.SetDefaultCanvasSize(100,100)
	return sys.getrefcount(r1) == 3
	
if "CONTEXT_CODE_GLFW3" in dir(dsight):
	assert(SingleContextHandlerInstance(dsight.CONTEXT_CODE_GLFW3))
	assert(DestructorResetStates(dsight.CONTEXT_CODE_GLFW3))
	assert(RemoveCanvas(dsight.CONTEXT_CODE_GLFW3))
	assert(CannotRemoveCanvasViewportTwice(dsight.CONTEXT_CODE_GLFW3))
	assert(SetDefaultCanvasSizeMustReturnItself(dsight.CONTEXT_CODE_GLFW3))
	assert(ChainWhithSetDefaultCanvasSize(dsight.CONTEXT_CODE_GLFW3))
	assert(CheckRefCountChainWhithSetDefaultCanvasSize(dsight.CONTEXT_CODE_GLFW3))
	assert(CheckRefCountSetDefaultCanvasSize(dsight.CONTEXT_CODE_GLFW3))
