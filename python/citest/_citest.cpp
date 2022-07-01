#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "citest/citest.hpp"

namespace py = pybind11;

namespace citest {

PYBIND11_MODULE(_citest, m)
{
  m.doc() = "Python Bindings for My C++ Project";
  m.def("add_one", &add_one, "Increments an integer value");
}

} // namespace citest
