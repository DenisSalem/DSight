#ifndef DSIGHT_PY_CANVAS_HPP_INCLUDED
#define DSIGHT_PY_CANVAS_HPP_INCLUDED

#include "python.hpp"
#include "Canvas/Canvas.hpp"
#include "Contexts/ContextCodes.hpp"
#include "Exceptions/ExceptionMessages.hpp"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    PyObject_HEAD
    PyObject *weakreflist;
    DSight::Canvas * cpp_obj;
} PythonCanvasObject;

extern PyTypeObject PythonCanvas;

PyObject *
Canvas_C_Side_init(DSight::Canvas * canvas);
#ifdef __cplusplus
}
#endif
#endif
