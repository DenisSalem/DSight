#ifndef DSIGHT_MACROS_HPP_INCLUDED
#define DSIGHT_MACROS_HPP_INCLUDED

#define DSIGHT_CATCH_BASE_EXCEPTION() \
catch (DSight::BaseException& e) { \
	PyObject* py_e = Py_BuildValue("(s,i)", e.message.c_str(), e.code); \
	PyErr_SetObject(PythonExceptionWrapper, py_e);\
	return NULL;\
}

#define DSIGHT_ADD_OBJECT_TO_MODULE(NAME) \
    Py_INCREF(&Python ## NAME);\
    PyModule_AddObject(m, # NAME, (PyObject *) &Python ## NAME);

#define PyDSightParseTuple(ARGS, FORMAT, ...) \
if (!PyArg_ParseTuple(ARGS, FORMAT , __VA_ARGS__)) { \
	PyErr_BadArgument(); \
	return NULL; \
}

#define DEFINE_DEFAULT_DSIGHT_PY_OBJECT_INIT(NAME) \
static PyObject * \
NAME ## _init(PyTypeObject *type, PyObject *args, PyObject * kw) \
{ \
	(void) type; \
	(void) args; \
	(void) kw; \
	PyObject* py_e = Py_BuildValue("(s,i)", DSIGHT_MSG_INSTANTIATION_ERROR, (long int) DSight::ExceptionCode::INSTANTIATION_ERROR); \
	PyErr_SetObject(PythonExceptionWrapper, py_e); \
	return NULL; \
}

#define DEFINE_DEFAULT_DSIGHT_PY_OBJECT_C_SIDE_INIT(NAME, ARG_TYPE, ARG) \
PyObject * \
NAME ## _C_Side_init(ARG_TYPE ARG) \
{ \
	Python ## NAME ## Object * self; \
    self = (Python ## NAME ## Object *) Python ## NAME.tp_alloc(&Python ## NAME, 0); \
	self->cpp_obj = &(ARG) ; \
	return (PyObject *) self; \
}

#endif
