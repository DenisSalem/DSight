#include <pybind11/pybind11.h>

#include "Contexts/ContextHandler.hpp"

namespace py = pybind11;

void InitContextHandler(py::module &m) {
    py::class_<DSight::ContextHandler<DSight::ContextGLFW3>>(m, "ContextHandler")
        .def(py::init<DSight::ContextCode, int, int>())
        .def("add_histogram", &DSight::ContextHandler<DSight::ContextGLFW3>::AddHistogram);
}

