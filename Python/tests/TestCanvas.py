#! /usr/bin/python3

import dsight

def DirectInstantiationForbidden():
	try:
		canvas = dsight.Canvas(1, 1, None)
	
	except dsight.PythonExceptionWrapper as e:
		message, code = e.args

		if (code == dsight.EXCEPTION_CODE_INSTANTIATION_ERROR):
			return 1;
			
		raise e

	return 0;

def AddOutOfBoundViewport(context_code):
	context = dsight.ContextHandler(context_code, 3, 3)
	canvas = context.AddCanvas(2, 2, None);
	try:
		canvas.AddViewport(0, 0, 4, 4);
	
	except dsight.PythonExceptionWrapper as e:
		message, code = e.args
		if code == dsight.EXCEPTION_CODE_INVALID_COORDINATES_OUT_OF_BOUNDS:
			return 1;
		
		raise e;
	
	return 0; 

def DoNotOverlap(context_code):
	context = dsight.ContextHandler(context_code, 3, 3)
	canvas = context.AddCanvas(4, 4, None)
	canvas.AddViewport(0, 0, 2, 2)
	try:
		canvas.AddViewport(2, 2, 5, 5)

	except dsight.PythonExceptionWrapper as e:
		message, code = e.args
		if code == dsight.EXCEPTION_CODE_INVALID_COORDINATES_OVERLAP:
			return 0

		raise e
	
	return 1


def PreventViewportOverlap(context_code):
	context = dsight.ContextHandler(context_code, 3, 3)
	canvas = context.AddCanvas(4, 4, None)
	canvas.AddViewport(0, 0, 2, 2)
	try:
		canvas.AddViewport(1, 1, 3, 3)

	except dsight.PythonExceptionWrapper as e:
		message, code = e.args
		if code == dsight.EXCEPTION_CODE_INVALID_COORDINATES_OVERLAP:
			return 1
		
		raise e
	
	return 0

def PreventViewportOverlapWithMultipleViewports(context_code):
	context = dsight.ContextHandler(context_code, 3,3)
	canvas = context.AddCanvas(1, 1, None)
	canvas.AddViewport(0,0,1,1)
	canvas.AddViewport(1,0,2,1)
	canvas.AddViewport(0,1,1,2)
	canvas.AddViewport(1,1,2,2)
	try:
		canvas.AddViewport(0,0,2,2)

	except dsight.PythonExceptionWrapper as e:
		message, code = e.args
		if code == dsight.EXCEPTION_CODE_INVALID_COORDINATES_OVERLAP:
			return 1
		
		raise e
	
	return 0

def PreventViewportOverlapFromZeroZeroToOneOne(context_code):
	context = dsight.ContextHandler(context_code, 3, 3)
	canvas = context.AddCanvas(2, 2, None)
	canvas.AddViewport(0, 0, 1, 1)
	try:
		canvas.AddViewport(0, 0, 1, 1)

	except dsight.PythonExceptionWrapper as e:
		message, code = e.args
		if code == dsight.EXCEPTION_CODE_INVALID_COORDINATES_OVERLAP:
			return 1
		
		raise e	
	
	return 0


def ZeroSubdivision(context_code):
	context = dsight.ContextHandler(context_code, 3,3)
	canvas = context.AddCanvas(0, 0, None)
	try:
		canvas.AddViewport(0,0,1,1)
		
	except dsight.PythonExceptionWrapper as e:
		message, code = e.args
		if e.code == dsight.EXCEPTION_CODE_INVALID_COORDINATES_OUT_OF_BOUNDS:
			return 0

		raise e	
	
	return 1

def RemoveViewport(context_code):
	context = dsight.ContextHandler(context_code, 3, 3)
	canvas = context.AddCanvas(0, 0, None)
	viewport = canvas.AddViewport(0, 0, 1, 1)
	return canvas.RemoveViewport(viewport)
	
def CannotRemoveViewportTwice(context_code):
	context = dsight.ContextHandler(context_code, 3, 3)
	canvas = context.AddCanvas(0, 0, None)
	viewport = canvas.AddViewport(0, 0, 1, 1)
	canvas.RemoveViewport(viewport)
	return not canvas.RemoveViewport(viewport)

assert(DirectInstantiationForbidden())
if "CONTEXT_CODE_GLFW3" in dir(dsight):
	assert(AddOutOfBoundViewport(dsight.CONTEXT_CODE_GLFW3))
	assert(DoNotOverlap(dsight.CONTEXT_CODE_GLFW3))
	assert(PreventViewportOverlap(dsight.CONTEXT_CODE_GLFW3))
	assert(PreventViewportOverlapWithMultipleViewports(dsight.CONTEXT_CODE_GLFW3))
	assert(PreventViewportOverlapFromZeroZeroToOneOne(dsight.CONTEXT_CODE_GLFW3))
	assert(ZeroSubdivision(dsight.CONTEXT_CODE_GLFW3))
	assert(RemoveViewport(dsight.CONTEXT_CODE_GLFW3))
	assert(CannotRemoveViewportTwice(dsight.CONTEXT_CODE_GLFW3))


	
