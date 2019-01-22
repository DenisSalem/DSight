#include <pybind11/pybind11.h>

#include "Contexts/ContextCodes.hpp"
#include "Exceptions/ExceptionCodes.hpp"

namespace py = pybind11;
		
void InitEnum(py::module &m) {
	py::enum_<DSight::ContextCode>(m, "ContextCode")
        .value("DSIGHT_CONTEXT_GLFW3", DSight::DSIGHT_CONTEXT_GLFW3)
        .value("DSIGHT_CONTEXT_GTK2_GL", DSight::DSIGHT_CONTEXT_GTK2_GL)
        .value("DSIGHT_CONTEXT_GTK3_GL", DSight::DSIGHT_CONTEXT_GTK3_GL)
        .value("DSIGHT_CONTEXT_SDL1_GL", DSight::DSIGHT_CONTEXT_SDL1_GL)
        .value("DSIGHT_CONTEXT_SDL2_GL", DSight::DSIGHT_CONTEXT_SDL2_GL)
        .export_values();
        
    py::enum_<DSight::ExceptionCode>(m, "ExceptionCode")
        .value("DSIGHT_EXCEPTION_MULTIPLE_CONTEXT", DSight::DSIGHT_EXCEPTION_MULTIPLE_CONTEXT)
        .value("DSIGHT_EXCEPTION_CONTEXT_INIT_FAILED", DSight::DSIGHT_EXCEPTION_CONTEXT_INIT_FAILED)
        .value("DSIGHT_EXCEPTION_UNSUPPORTED_CONTEXT", DSight::DSIGHT_EXCEPTION_UNSUPPORTED_CONTEXT)
        .value("DSIGHT_EXCEPTION_CANVAS_CREATION_FAILED", DSight::DSIGHT_EXCEPTION_CANVAS_CREATION_FAILED)
        .value("DSIGHT_EXCEPTION_CANVAS_DOESNT_EXISTS", DSight::DSIGHT_EXCEPTION_CANVAS_DOESNT_EXISTS)
        .value("DSIGHT_EXCEPTION_MISMATCH_BETWEEN_PARAMS_LENGHT", DSight::DSIGHT_EXCEPTION_MISMATCH_BETWEEN_PARAMS_LENGHT)
        .export_values();
}
