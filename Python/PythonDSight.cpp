#include "PythonDSight.hpp"

PYBIND11_MODULE(dsight, m) {
	InitEnum(m);
	InitExceptions(m);
	InitContextHandler(m);
}