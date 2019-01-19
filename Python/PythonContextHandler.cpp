#include <pybind11/pybind11.h>

#include "Contexts/ContextHandler.hpp"

namespace py = pybind11;

void InitContextHandler(py::module &m) {
    py::class_<DSight::ContextHandler<DSight::ContextGLFW3>>(m, "ContextHandler")
        .def(py::init<DSight::ContextCode, int, int>())
        .def("test_display_window", &DSight::ContextHandler<DSight::ContextGLFW3>::LoopRender);
}

