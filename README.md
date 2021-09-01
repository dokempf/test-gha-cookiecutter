# Welcome to My C++ Project

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/dokempf/test-github-actions-cookiecutter-cpp-project/CI)](https://github.com/dokempf/test-github-actions-cookiecutter-cpp-project/actions?query=workflow%3ACI)
[![PyPI Release](https://img.shields.io/pypi/v/testgithubactionscookiecuttercppproject.svg)](https://pypi.org/project/testgithubactionscookiecuttercppproject)
[![Documentation Status](https://readthedocs.org/projects/test-github-actions-cookiecutter-cpp-project/badge/)](https://test-github-actions-cookiecutter-cpp-project.readthedocs.io/)
[![codecov](https://codecov.io/gh/dokempf/test-github-actions-cookiecutter-cpp-project/branch/main/graph/badge.svg)](https://codecov.io/gh/dokempf/test-github-actions-cookiecutter-cpp-project)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=dokempf_test-github-actions-cookiecutter-cpp-project&metric=alert_status)](https://sonarcloud.io/dashboard?id=dokempf_test-github-actions-cookiecutter-cpp-project)

# Prerequisites

Building My C++ Project requires the following software installed:

* A C++11-compliant compiler
* CMake `>= 3.9`
* Doxygen (optional, documentation building is skipped if missing)
* The testing framework [Catch2](https://github.com/catchorg/Catch2) for building the test suite* Python `>= 3.6` for building Python bindings* The [PyBind11](https://github.com/pybind/pybind11) library for building Python bindings

# Building My C++ Project

The following sequence of commands builds My C++ Project.
It assumes that your current working directory is the top-level directory
of the freshly cloned repository:

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

The build process can be customized with the following CMake variables,
which can be set by adding `-D<var>={ON, OFF}` to the `cmake` call:

* `BUILD_TESTING`: Enable building of the test suite (default: `ON`)
* `BUILD_DOCS`: Enable building the documentation (default: `ON`)
* `BUILD_PYTHON`: Enable building the Python bindings (default: `ON`)

# Documentation

My C++ Project provides a Sphinx-based documentation, that can
be browsed [online at readthedocs.org](https://test-github-actions-cookiecutter-cpp-project.readthedocs.io).
