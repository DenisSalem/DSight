#include <pybind11/pybind11.h>

#include "Charts/HistogramCPU.hpp"
#include "Charts/HistogramGL.hpp"

namespace py = pybind11;

void InitCharts(py::module &m) {
    py::class_<DSight::HistogramCPU>(m, "HistogramCPU")
        .def(py::init<DSight::HistogramCPU>())
        .def("draw", &DSight::HistogramCPU::Draw);
        
	py::class_<DSight::HistogramGL>(m, "HistogramGL")
		.def(py::init<DSight::HistogramGL>())
        .def("draw", &DSight::HistogramGL::Draw);
}
