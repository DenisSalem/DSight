#include "PythonExceptionWrapper.hpp"
#include "PythonCanvas.hpp"
#include "PythonViewport.hpp"
#include "Macros.hpp"

#ifdef __cplusplus
extern "C" {
#endif

PyObject * 
AddViewport(PythonCanvasObject *self, PyObject * args) {
	int tl_x;
	int tl_y;
	int br_x;
	int br_y;
	
	DSIGHT_PY_PARSE_TUPLE(args, "iiii", &tl_x, &tl_y, &br_x, &br_y)
	
	try {
		self->m_py_viewports.push_back(
			(PythonViewportObject *) Viewport_C_Side_init(
				self->cpp_obj->AddViewport(tl_x, tl_y, br_x, br_y)
			)
		);
	}
	catch (std::bad_alloc &e) {
		return PyErr_NoMemory();
	}
	DSIGHT_CATCH_BASE_EXCEPTION()
	
	PythonViewportObject * viewport = self->m_py_viewports.back();
	Py_INCREF(viewport);
	return (PyObject *) viewport;
}

PyObject * 
RemoveViewport(PythonCanvasObject *self, PyObject * args) {
	PythonViewportObject * viewport = NULL;
	
	DSIGHT_PY_PARSE_TUPLE(args, "O!", &PythonViewport, &viewport)

	for(unsigned int i = 0; i < self->m_py_viewports.size(); i++) {
		if (self->m_py_viewports[i]->cpp_obj == viewport->cpp_obj) {
			self->m_py_viewports.erase(self->m_py_viewports.begin() + i);
			bool ret = self->cpp_obj->RemoveViewport( *(viewport->cpp_obj) );
			Py_DECREF(viewport);
			return PyBool_FromLong(ret);
		}
	}
	return PyBool_FromLong(0);
}

static void
Canvas_dealloc(PythonCanvasObject *self)
{
	PyObject *error_type, *error_value, *error_traceback;
    PyErr_Fetch(&error_type, &error_value, &error_traceback);
    
	if (self->weakreflist != NULL) {
        PyObject_ClearWeakRefs((PyObject *) self);
	}
	
    Py_TYPE(self)->tp_free((PyObject *) self);
	
    PyErr_Restore(error_type, error_value, error_traceback);
}

DSIGHT_DEFINE_DEFAULT_PY_OBJECT_INIT(Canvas)

static PyMethodDef Canvas_methods[] = {
    {"AddViewport", (PyCFunction) AddViewport, METH_VARARGS, "Add viewport."},
    {"RemoveViewport", (PyCFunction) RemoveViewport, METH_VARARGS, "Remove viewport."},
    {0, 0, 0, 0}  /* Sentinel */
};

DSIGHT_DEFINE_NEW_PY_TYPE(Canvas, "Context's Canvas.")
DSIGHT_DEFINE_DEFAULT_PY_OBJECT_C_SIDE_INIT(Canvas, DSight::Canvas&, canvas)

#ifdef __cplusplus
}
#endif
