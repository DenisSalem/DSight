#include <pybind11/pybind11.h>

#include "Exceptions/DSightBaseException.hpp"

namespace py = pybind11;

void InitExceptions(py::module &m) {
	py::register_exception<DSight::DSightBaseException>(m, "DSightBaseException");
}
