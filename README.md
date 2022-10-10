# Welcome to My C++ Project

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/dokempf/test-gha-cookiecutter/CI)](https://github.com/dokempf/test-gha-cookiecutter/actions?query=workflow%3ACI)
[![PyPI Release](https://img.shields.io/pypi/v/testghacookiecutter.svg)](https://pypi.org/project/testghacookiecutter)
[![Documentation Status](https://readthedocs.org/projects/test-gha-cookiecutter/badge/)](https://test-gha-cookiecutter.readthedocs.io/)
[![codecov](https://codecov.io/gh/dokempf/test-gha-cookiecutter/branch/main/graph/badge.svg)](https://codecov.io/gh/dokempf/test-gha-cookiecutter)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=dokempf_test-gha-cookiecutter&metric=alert_status)](https://sonarcloud.io/dashboard?id=dokempf_test-gha-cookiecutter)

# Prerequisites

Building My C++ Project requires the following software installed:

* A C++11-compliant compiler
* CMake `>= 3.9`
* Doxygen (optional, documentation building is skipped if missing)
* The testing framework [Catch2](https://github.com/catchorg/Catch2) for building the test suite* Python `>= 3.8` for building Python bindings

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


If you wish to build and install the project as a Python project without
having access to C++ build artifacts like libraries and executables, you
can do so using `pip` from the root directory:

```
python -m pip install .
```

# Testing My C++ Project

When built according to the above explanation (with `-DBUILD_TESTING=ON`),
the C++ test suite of `My C++ Project` can be run using
`ctest` from the build directory:

```
cd build
ctest
```

The Python test suite can be run by first `pip`-installing the Python package
and then running `pytest` from the top-level directory:

```
python -m pip install .
pytest
```

# Documentation

My C++ Project provides a Sphinx-based documentation, that can
be browsed [online at readthedocs.org](https://test-gha-cookiecutter.readthedocs.io).
To build it locally, first ensure the requirements are installed by running this command from the top-level source directory:

```
pip install -r doc/requirements.txt
```

Then build the sphinx documentation from the top-level build directory:

```
cmake --build . --target sphinx-doc
```

The web documentation can then be browsed by opening `doc/sphinx/index.html` in your browser.
