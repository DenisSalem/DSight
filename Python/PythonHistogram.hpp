#ifndef DSIGHT_PY_HISTOGRAM_GL_HPP_INCLUDED
#define DSIGHT_PY_HISTOGRAM_GL_HPP_INCLUDED

#include "python.hpp"
#include "Contexts/ContextCodes.hpp"
#include "Exceptions/BaseException.hpp"
#include "Charts/Histogram.hpp"


#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    PyObject_HEAD
    PyObject *weakreflist;
    DSight::Histogram * cpp_obj;
} PythonHistogramObject;

extern PyTypeObject PythonHistogram;
PyObject *
Histogram_C_Side_init(DSight::Histogram& histogram);
#ifdef __cplusplus
}
#endif
#endif
