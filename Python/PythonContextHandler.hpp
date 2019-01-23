#include <python3.6m/Python.h>
#include "Contexts/ContextHandler.hpp"
#include "Contexts/ContextCodes.hpp"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    PyObject_HEAD
    DSight::ContextHandler * cpp_obj;
} PythonContextHandlerObject;

extern PyTypeObject PythonContextHandler;

#ifdef __cplusplus
}
#endif
