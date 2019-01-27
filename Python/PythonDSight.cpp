#include <python3.6m/Python.h>
#include "Contexts/ContextCodes.hpp"
#include "Exceptions/ExceptionCodes.hpp"

#include "PythonCanvas.hpp"
#include "PythonContextHandler.hpp"
#include "PythonExceptionWrapper.hpp"

#ifdef __cplusplus
extern "C" {
#endif

static PyModuleDef dsight = {
    PyModuleDef_HEAD_INIT,
    .m_name = "dsight",
    .m_doc = "A Chart library. Low level implementation, High level API.",
    .m_size = -1,
    .m_methods = 0,
    .m_slots = 0,
    .m_traverse = 0,
    .m_clear = 0,
    .m_free = 0
};

PyMODINIT_FUNC
PyInit_dsight(void)
{
    PyObject *m;

    if (PyType_Ready(&PythonContextHandler) < 0)
        return NULL;
        
    if (PyType_Ready(&PythonCanvas) < 0)
        return NULL;
                       
    m = PyModule_Create(&dsight);
    if (m == NULL) {
        return NULL;
	}

	// DEFINES EXCEPTIONS
		
	PythonExceptionWrapper = PyErr_NewException("dsight.PythonExceptionWrapper", NULL, NULL);
	Py_INCREF(PythonExceptionWrapper);
    PyModule_AddObject(m, "PythonExceptionWrapper", PythonExceptionWrapper);

	// DEFINES PUBLIC OBJECTS

    Py_INCREF(&PythonContextHandler);
    PyModule_AddObject(m, "ContextHandler", (PyObject *) &PythonContextHandler);
    
    Py_INCREF(&PythonCanvas);
    PyModule_AddObject(m, "Canvas", (PyObject *) &PythonCanvas);

	// DEFINES CONSTANTS
  
	#ifdef _USE_GLFW3_
    PyModule_AddIntConstant(m, "CONTEXT_CODE_GLFW3", (long int) DSight::ContextCode::GLFW3);
	#endif
	
    PyModule_AddIntConstant(m, "EXCEPTION_CODE_CANVAS_CREATION_FAILED", (long int) DSight::ExceptionCode::CANVAS_CREATION_FAILED);
    PyModule_AddIntConstant(m, "EXCEPTION_CODE_CANVAS_DOESNT_EXISTS", (long int) DSight::ExceptionCode::CANVAS_DOESNT_EXISTS);
    PyModule_AddIntConstant(m, "EXCEPTION_CODE_CONTEXT_INIT_FAILED", (long int) DSight::ExceptionCode::CONTEXT_INIT_FAILED);
    PyModule_AddIntConstant(m, "EXCEPTION_CODE_INVALID_COORDINATES_OUT_OUF_BOUNDS", (long int) DSight::ExceptionCode::INVALID_COORDINATES_OUT_OF_BOUNDS);
    PyModule_AddIntConstant(m, "EXCEPTION_CODE_INVALID_COORDINATES_OVERLAP", (long int) DSight::ExceptionCode::INVALID_COORDINATES_OVERLAP);
    PyModule_AddIntConstant(m, "EXCEPTION_CODE_INVALID_COORDINATES", (long int) DSight::ExceptionCode::INVALID_COORDINATES);
    PyModule_AddIntConstant(m, "EXCEPTION_CODE_MISMATCH_BETWEEN_PARAMS_LENGHT", (long int) DSight::ExceptionCode::MISMATCH_BETWEEN_PARAMS_LENGHT);
    PyModule_AddIntConstant(m, "EXCEPTION_CODE_MULTIPLE_CONTEXT", (long int) DSight::ExceptionCode::MULTIPLE_CONTEXT);
    PyModule_AddIntConstant(m, "EXCEPTION_CODE_UNSUPPORTED_CONTEXT", (long int) DSight::ExceptionCode::UNSUPPORTED_CONTEXT);
    PyModule_AddIntConstant(m, "EXCEPTION_CODE_INSTANTIATION_ERROR", (long int) DSight::ExceptionCode::INSTANTIATION_ERROR);
    
    return m;
}

#ifdef __cplusplus
}
#endif
