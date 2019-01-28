#include "python.hpp"
#include "Contexts/ContextHandler.hpp"
#include "Contexts/ContextCodes.hpp"
#include "Exceptions/BaseException.hpp"

#include "PythonCanvas.hpp"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    PyObject_HEAD
    PyObject *weakreflist;
    DSight::ContextHandler * cpp_obj;
    std::vector<PythonCanvasObject *> m_py_canvas;
} PythonContextHandlerObject;

extern PyTypeObject PythonContextHandler;

#ifdef __cplusplus
}
#endif
