#include <pybind11/pybind11.h>

namespace py = pybind11;

void InitContextHandler(py::module &m);
void InitExceptions(py::module &m);
void InitEnum(py::module &m);