#include "PythonHistogram.hpp"
#include "PythonExceptionWrapper.hpp"
#include "Macros.hpp"
#include "Contexts/ContextHandler.hpp"

#ifdef __cplusplus
extern "C" {
#endif

PyObject * 
HistogramDraw(PythonHistogramObject *self) {
	(void) self;
	DSight::ContextHandler::Draw();
	Py_RETURN_NONE;
}

static void
Histogram_dealloc(PythonHistogramObject *self)
{
	PyObject *error_type, *error_value, *error_traceback;
    PyErr_Fetch(&error_type, &error_value, &error_traceback);
    
	if (self->weakreflist != NULL) {
        PyObject_ClearWeakRefs((PyObject *) self);
	}
	
    Py_TYPE(self)->tp_free((PyObject *) self);
	delete self->cpp_obj;
	
    PyErr_Restore(error_type, error_value, error_traceback);
}

static PyObject *
Histogram_init(PyTypeObject *type, PyObject *args, PyObject * kw)
{
	(void) kw;
    PythonHistogramObject * self;
    self = (PythonHistogramObject *) type->tp_alloc(type, 0);
    
    if (self != NULL) {
		try {
			self->cpp_obj = new DSight::Histogram();
		} catch (std::bad_alloc&) {
			return PyErr_NoMemory();
		}
		DSIGHT_CATCH_BASE_EXCEPTION()
    }
    
    return (PyObject *) self;
}

static PyMethodDef Histogram_methods[] = {
    {"Draw", (PyCFunction) HistogramDraw, METH_NOARGS, "Draw Canvas."},
    {0, 0, 0, 0}  /* Sentinel */
};

DSIGHT_DEFINE_NEW_PY_TYPE(Histogram, "Histogram.")
DSIGHT_DEFINE_DEFAULT_PY_OBJECT_C_SIDE_INIT(Histogram, DSight::Histogram&, histogram)

#ifdef __cplusplus
}
#endif
