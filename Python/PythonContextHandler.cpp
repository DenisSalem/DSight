#include "PythonContextHandler.hpp"

#ifdef __cplusplus
extern "C" {
#endif

static void
ContextHandler_dealloc(PythonContextHandlerObject *self)
{
	delete self->cpp_obj;
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
ContextHandler_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    PythonContextHandlerObject * self;
    self = (PythonContextHandlerObject *) type->tp_alloc(type, 0);
    
    
    if (self != NULL) {
		try {
			self->cpp_obj = new DSight::ContextHandler(DSight::DSIGHT_CONTEXT_GLFW3, 3, 3);
		} catch (std::bad_alloc&) {
			// TODO
		}
    }
    
    return (PyObject *) self;
}

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
    
    0, //long tp_weaklistoffset

    // Added in release 2.2
    // Iterators
    
    0, //getiterfunc tp_iter
    0, //iternextfunc tp_iternext

    // Attribute descriptor and subclassing stuff
    
    0, //struct PyMethodDef *tp_methods
    0, //struct PyMemberDef *tp_members
    0, //struct PyGetSetDef *tp_getset
    0, //struct _typeobject *tp_base
    0, //PyObject *tp_dict
    0, //descrgetfunc tp_descr_get
    0, //descrsetfunc tp_descr_set
    0, //long tp_dictoffset
    0, //initproc tp_init
    0, //allocfunc tp_alloc
    ContextHandler_new, //newfunc tp_new
    
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
