#include "PythonContextHandler.hpp"
#include "PythonExceptionWrapper.hpp"
#include "Macros.hpp"

#ifdef __cplusplus
extern "C" {
#endif

PyObject * 
AddCanvas(PythonContextHandlerObject *self, PyObject * args) {
	int horizontal_subdivision;
	int vertical_subdivision;
	const char * canvas_name = NULL;
	
	DSIGHT_PY_PARSE_TUPLE(args, "iiz", &horizontal_subdivision, &vertical_subdivision, &canvas_name)
	
	if (canvas_name != NULL) {
		self->m_canvas_names.push_back(std::string(canvas_name));
	}
	else {
		self->m_canvas_names.push_back(std::string(""));
	}
	
	try {
		self->m_py_canvas.push_back(
			(PythonCanvasObject *) Canvas_C_Side_init(
				self->cpp_obj->AddCanvas(horizontal_subdivision, vertical_subdivision, self->m_canvas_names.back().c_str())
			)
		);
	}
	catch (std::bad_alloc &e) {
		return PyErr_NoMemory();
	}
	PythonCanvasObject * canvas = self->m_py_canvas.back();
	Py_INCREF(canvas);
	return (PyObject*) canvas;
}

PyObject * 
RemoveCanvas(PythonContextHandlerObject *self, PyObject * args) {
	PythonCanvasObject * canvas = NULL;
	
	DSIGHT_PY_PARSE_TUPLE(args, "O!", &PythonCanvas, &canvas)

	for(unsigned int i = 0; i < self->m_py_canvas.size(); i++) {
		if (self->m_py_canvas[i]->cpp_obj == canvas->cpp_obj) {
			self->m_py_canvas.erase(self->m_py_canvas.begin() + i);
			self->m_canvas_names.erase(self->m_canvas_names.begin() + i);
			bool ret = self->cpp_obj->RemoveCanvas( *(canvas->cpp_obj) );
			Py_DECREF(canvas);
			return PyBool_FromLong(ret);
		}
	}
	return PyBool_FromLong(0);
}

PyObject * 
SetDefaultCanvasSize(PythonContextHandlerObject *self, PyObject * args) {
	Py_XINCREF( (PyObject *) self);
	int default_width;
	int default_height;
	
	DSIGHT_PY_PARSE_TUPLE(args, "ii", &default_width, &default_height)

	self->cpp_obj->SetDefaultCanvasSize(default_width, default_height);
	return (PyObject *) self;
}

static void
ContextHandler_dealloc(PythonContextHandlerObject *self)
{
	PyObject *error_type, *error_value, *error_traceback;
    PyErr_Fetch(&error_type, &error_value, &error_traceback);
    
	if (self->weakreflist != NULL) {
        PyObject_ClearWeakRefs((PyObject *) self);
	}
	
	for (unsigned int i = 0; i < self->m_py_canvas.size(); i++) {
		Py_XDECREF(self->m_py_canvas[i]);
	}
	
    Py_TYPE(self)->tp_free((PyObject *) self);
	delete self->cpp_obj;
	
    PyErr_Restore(error_type, error_value, error_traceback);
}

static PyObject *
ContextHandler_init(PyTypeObject *type, PyObject *args, PyObject * kw)
{
	(void) kw;
    PythonContextHandlerObject * self;
    self = (PythonContextHandlerObject *) type->tp_alloc(type, 0);
 
	int context_code, maj, min;
	if (!PyArg_ParseTuple(args, "iii", &context_code, &maj, &min)) {
		PyErr_BadArgument();
		return NULL;
	}
    
    if (self != NULL) {
		try {
			self->cpp_obj = new DSight::ContextHandler((DSight::ContextCode) context_code, maj, min);
		} catch (std::bad_alloc&) {
			return PyErr_NoMemory();
		}
		DSIGHT_CATCH_BASE_EXCEPTION()
    }
    
    return (PyObject *) self;
}

static PyMethodDef ContextHandler_methods[] = {
    {"AddCanvas", (PyCFunction) AddCanvas, METH_VARARGS, "Add Canvas."},
    {"RemoveCanvas", (PyCFunction) RemoveCanvas, METH_VARARGS, "Remove Canvas."},
    {"SetDefaultCanvasSize", (PyCFunction) SetDefaultCanvasSize, METH_VARARGS, "Set default canvas size."},
    {0, 0, 0, 0}  /* Sentinel */
};

DSIGHT_DEFINE_NEW_PY_TYPE(ContextHandler, "Context Handler.")

#ifdef __cplusplus
}
#endif
