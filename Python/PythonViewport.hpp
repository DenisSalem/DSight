#ifndef DSIGHT_PY_VIEWPORT_HPP_INCLUDED
#define DSIGHT_PY_VIEWPORT_HPP_INCLUDED

#include "python.hpp"
#include "Viewport/Viewport.hpp"
#include "Exceptions/ExceptionMessages.hpp"
#include "Exceptions/ExceptionCodes.hpp"
#
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    PyObject_HEAD
    PyObject *weakreflist;
    DSight::Viewport * cpp_obj;
} PythonViewportObject;

extern PyTypeObject PythonViewport;

PyObject *
Viewport_C_Side_init(DSight::Viewport& viewport);
#ifdef __cplusplus
}
#endif
#endif
