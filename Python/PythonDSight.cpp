#include <python3.6m/Python.h>
#include "PythonContextHandler.hpp"

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

    m = PyModule_Create(&dsight);
    if (m == NULL)
        return NULL;

    Py_INCREF(&PythonContextHandler);
    PyModule_AddObject(m, "ContextHandler", (PyObject *) &PythonContextHandler);
    return m;
}

#ifdef __cplusplus
}
#endif
