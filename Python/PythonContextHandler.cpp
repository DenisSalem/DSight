#include <pybind11/pybind11.h>

#include "Contexts/ContextCodes.hpp"
#include "Contexts/ContextHandler.hpp"
#include "Exceptions/ExceptionCodes.hpp"
#include "Exceptions/DSightBaseException.hpp"

namespace py = pybind11;

/*
PYBIND11_MODULE(pybind11_example, m) {
    m.doc() = "pybind11 example";

    py::enum_<Sentiment>(m, "Sentiment")
        .value("Angry", Angry)
        .value("Happy", Happy)
        .value("Confused", Confused)
        .export_values();

    m.def("mood", &mood, "Demonstrate using an enum");
} */

PYBIND11_MODULE(dsight, m) {
    py::class_<DSight::ContextHandler<DSight::ContextGLFW3>>(m, "ContextHandler")
        .def(py::init<DSight::ContextCode, int, int>())
        .def("test_display_window", &DSight::ContextHandler<DSight::ContextGLFW3>::TestDisplayWindow);
        
	py::enum_<DSight::ContextCode>(m, "ContextCode")
        .value("DSIGHT_CONTEXT_GLFW3", DSight::DSIGHT_CONTEXT_GLFW3)
        .value("DSIGHT_CONTEXT_GTK2", DSight::DSIGHT_CONTEXT_GTK2)
        .value("DSIGHT_CONTEXT_GTK3", DSight::DSIGHT_CONTEXT_GTK3)
        .value("DSIGHT_CONTEXT_SDL1", DSight::DSIGHT_CONTEXT_SDL1)
        .value("DSIGHT_CONTEXT_SDL2", DSight::DSIGHT_CONTEXT_SDL2)
        .export_values();
}

