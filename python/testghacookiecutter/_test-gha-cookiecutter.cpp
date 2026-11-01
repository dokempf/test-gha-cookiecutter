#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "test-gha-cookiecutter/test-gha-cookiecutter.hpp"

namespace py = pybind11;

namespace testghacookiecutter {

PYBIND11_MODULE(_testghacookiecutter, m)
{
  m.doc() = "Python Bindings for My C++ Project";
  m.def("add_one", &add_one, "Increments an integer value");
}

} // namespace testghacookiecutter
