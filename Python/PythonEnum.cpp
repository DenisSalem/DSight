#include <pybind11/pybind11.h>

#include "Contexts/ContextCodes.hpp"
#include "Exceptions/ExceptionCodes.hpp"

namespace py = pybind11;
		
void InitEnum(py::module &m) {
	py::enum_<DSight::ContextCode>(m, "ContextCode")
        .value("DSIGHT_CONTEXT_GLFW3", DSight::DSIGHT_CONTEXT_GLFW3)
        .value("DSIGHT_CONTEXT_GTK2", DSight::DSIGHT_CONTEXT_GTK2)
        .value("DSIGHT_CONTEXT_GTK3", DSight::DSIGHT_CONTEXT_GTK3)
        .value("DSIGHT_CONTEXT_SDL1", DSight::DSIGHT_CONTEXT_SDL1)
        .value("DSIGHT_CONTEXT_SDL2", DSight::DSIGHT_CONTEXT_SDL2)
        .export_values();
        
    py::enum_<DSight::ExceptionCode>(m, "ExceptionCode")
        .value("DSIGHT_EXCEPTION_MULTIPLE_CONTEXT", DSight::DSIGHT_EXCEPTION_MULTIPLE_CONTEXT)
        .value("DSIGHT_EXCEPTION_CONTEXT_INIT_FAILED", DSight::DSIGHT_EXCEPTION_CONTEXT_INIT_FAILED)
        .value("DSIGHT_EXCEPTION_UNSUPPORTED_CONTEXT", DSight::DSIGHT_EXCEPTION_UNSUPPORTED_CONTEXT)
        .value("DSIGHT_EXCEPTION_SURFACE_CREATION_FAILED", DSight::DSIGHT_EXCEPTION_SURFACE_CREATION_FAILED)
        .value("DSIGHT_SURFACE_DOESNT_EXISTS", DSight::DSIGHT_SURFACE_DOESNT_EXISTS)
        .export_values();
}
