#include <pybind11/pybind11.h>

namespace py = pybind11;


void InitEnum(py::module &m);
void InitExceptions(py::module &m);
void InitCharts(py::module &m);
void InitContextHandler(py::module &m);


