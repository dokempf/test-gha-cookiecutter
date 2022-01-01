#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "test-github-actions-cookiecutter-cpp-project/test-github-actions-cookiecutter-cpp-project.hpp"

namespace py = pybind11;

namespace testgithubactionscookiecuttercppproject {

PYBIND11_MODULE(testgithubactionscookiecuttercppproject, m)
{
  m.doc() = "Python Bindings for My C++ Project";
  m.def("add_one", &add_one, "Increments an integer value");
}

} // namespace testgithubactionscookiecuttercppproject
