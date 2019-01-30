#include "PythonViewport.hpp"
#include "PythonExceptionWrapper.hpp"
#include "PythonHistogram.hpp"
#include "Macros.hpp"

#ifdef __cplusplus
extern "C" {
#endif

PyObject * 
SetHistogram(PythonViewportObject *self, PyObject * args) {
	//DSIGHT_PY_PARSE_TUPLE(args, "iiii", &tl_x, &tl_y, &br_x, &br_y)
	
	try {
		self->m_py_histogram = (PythonHistogramObject * ) Histogram_C_Side_init(
			self->cpp_obj->SetHistogram()
		);
	}
	catch (std::bad_alloc &e) {
		return PyErr_NoMemory();
	}
	DSIGHT_CATCH_BASE_EXCEPTION()
	
	Py_INCREF(self->m_py_histogram);
	return (PyObject *) self->m_py_histogram;
}

static void
Viewport_dealloc(PythonViewportObject *self)
{
	PyObject *error_type, *error_value, *error_traceback;
    PyErr_Fetch(&error_type, &error_value, &error_traceback);
    
	if (self->weakreflist != NULL) {
        PyObject_ClearWeakRefs((PyObject *) self);
	}
		
    Py_TYPE(self)->tp_free((PyObject *) self);	
    PyErr_Restore(error_type, error_value, error_traceback);
}

DSIGHT_DEFINE_DEFAULT_PY_OBJECT_INIT(Viewport)

static PyMethodDef Viewport_methods[] = {
	{"SetHistogram", (PyCFunction) SetHistogram, METH_VARARGS, "Set Histogram."},
    {0, 0, 0, 0}  /* Sentinel */
};

DSIGHT_DEFINE_NEW_PY_TYPE(Viewport, "Viewport.")
DSIGHT_DEFINE_DEFAULT_PY_OBJECT_C_SIDE_INIT(Viewport, DSight::Viewport&, viewport)

#ifdef __cplusplus
}
#endif
