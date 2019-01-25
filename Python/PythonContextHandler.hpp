#include "python.hpp"
#include "Contexts/ContextHandler.hpp"
#include "Contexts/ContextCodes.hpp"
#include "Exceptions/BaseException.hpp"

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
