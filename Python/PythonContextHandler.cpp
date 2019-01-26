#include "PythonContextHandler.hpp"
#include "PythonExceptionWrapper.hpp"

#ifdef __cplusplus
extern "C" {
#endif

PyObject * 
AddCanvas(PythonContextHandlerObject *self, PyObject * args, PyObject * kw) {
	return Canvas_C_Side_init(self->cpp_obj->AddCanvas(3,3));
}

static void
ContextHandler_dealloc(PythonContextHandlerObject *self)
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
ContextHandler_init(PyTypeObject *type, PyObject *args, PyObject *kw)
{
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
		catch (DSight::BaseException& e) {
			PyObject* py_e = Py_BuildValue("(s,i)", e.message.c_str(), e.code);
			PyErr_SetObject(PythonExceptionWrapper, py_e);			
			return NULL;
		}
    }
    
    return (PyObject *) self;
}

static PyMethodDef ContextHandler_methods[] = {
    {"AddCanvas", (PyCFunction) AddCanvas, METH_NOARGS,
     "Add Canvas"
    },
    {NULL}  /* Sentinel */
};

PyTypeObject PythonContextHandler = {
    PyVarObject_HEAD_INIT(NULL, 0)
    
    // For printing, in format "<module>.<name>"
    
    "dsight.ContextHandler", // char *tp_name 
    
    // For allocation
	
	sizeof(PythonContextHandlerObject), //int tp_basicsize 
	0, //int tp_itemsize
	
	// Methods to implement standard operations
    
    (destructor) ContextHandler_dealloc, //destructor tp_dealloc
    0, //printfunc tp_print
    0, //getattrfunc tp_getattr
    0, //etattrfunc tp_setattr
    0, //cmpfunc tp_compare
    0, //reprfunc tp_repr;
    
    // Method suites for standard classes

    0, //PyNumberMethods *tp_as_number
    0, //PySequenceMethods *tp_as_sequence
    0, //PyMappingMethods *tp_as_mapping
    
	// More standard operations (here for binary compatibility)

    0, //hashfunc tp_hash
    0, //ternaryfunc tp_call
    0, //reprfunc tp_str
    0, //getattrofunc tp_getattro
    0, //setattrofunc tp_setattro

    // Functions to access object as input/output buffer
    
    0, //PyBufferProcs *tp_as_buffer

    // Flags to define presence of optional/expanded features
    Py_TPFLAGS_DEFAULT, //long tp_flags

	// Documentation string
    "Context Handler", //char *tp_doc

    // Assigned meaning in release 2.0
    // call function for all accessible objects
     
    0, //traverseproc tp_traverse

    // delete references to contained objects
    
    0, //inquiry tp_clear

    // Assigned meaning in release 2.1
    // rich comparisons
    
    0, //richcmpfunc tp_richcompare

    // weak reference enabler
    
    offsetof(PythonContextHandlerObject, weakreflist), //long tp_weaklistoffset

    // Added in release 2.2
    // Iterators
    
    0, //getiterfunc tp_iter
    0, //iternextfunc tp_iternext

    // Attribute descriptor and subclassing stuff
    
    ContextHandler_methods, //struct PyMethodDef *tp_methods
    0, //struct PyMemberDef *tp_members
    0, //struct PyGetSetDef *tp_getset
    0, //struct _typeobject *tp_base
    0, //PyObject *tp_dict
    0, //descrgetfunc tp_descr_get
    0, //descrsetfunc tp_descr_set
    0, //long tp_dictoffset
    0, //initproc tp_init
    0, //allocfunc tp_alloc
    ContextHandler_init, //newfunc tp_new
    
    // Low-level free-memory routine
    
    0, //freefunc tp_free
    
    // For PyObject_IS_GC
    
    0, //inquiry tp_is_gc
    0, //PyObject *tp_bases
    
	// method resolution order
    
    0, //PyObject *tp_mro
    0, //PyObject *tp_cache
    0, //PyObject *tp_subclasses
    0, //PyObject *tp_weaklist
    0, //destructor tp_del

    // Type attribute cache version tag. Added in version 2.6
    
    0, //unsigned int tp_version_tag
    0, //destructor tp_finalize
};

#ifdef __cplusplus
}
#endif
