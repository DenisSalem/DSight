#include "PythonDSight.hpp"

PYBIND11_MODULE(dsight, m) {
	InitEnum(m);
	InitExceptions(m);
	InitCharts(m);
	InitContextHandler(m);
	m.def("create_dict", &create_dict, py::return_value_policy::reference);
}
