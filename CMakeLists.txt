cmake_minimum_required(VERSION 3.23)

# Set a name and a version number for your project:
project(
  test-gha-cookiecutter
  VERSION 0.0.1
  LANGUAGES CXX)

# Initialize some default paths
include(GNUInstallDirs)

# Enable PIC for Python bindings
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# Compilation options
option(BUILD_PYTHON "Enable building of Python bindings" OFF)
option(BUILD_DOCS "Enable building of documentation" ON)

# Add an interface target for the header-only library
add_library(test-gha-cookiecutter INTERFACE)

# Add the public headers that belong to this library
target_sources(
  test-gha-cookiecutter
  INTERFACE FILE_SET HEADERS BASE_DIRS include FILES
            include/test-gha-cookiecutter/test-gha-cookiecutter.hpp)

# Request a minimum C++ standard for this target
target_compile_features(test-gha-cookiecutter INTERFACE cxx_std_14)

# Compile the application executable
add_subdirectory(app)

# Compile the tests
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()

# Add the documentation
if(BUILD_DOCS)
  add_subdirectory(doc)
endif()
# Add Python bindings
if(BUILD_PYTHON)
  find_package(pybind11 REQUIRED)
  # Compile the Pybind11 module
  pybind11_add_module(_testghacookiecutter
                      python/testghacookiecutter/_test-gha-cookiecutter.cpp)
  target_link_libraries(_testghacookiecutter PUBLIC test-gha-cookiecutter)

  # Install the Python module shared library
  install(TARGETS _testghacookiecutter DESTINATION .)
endif()

# Add an alias target for use if this project is included as a subproject in
# another project
add_library(test-gha-cookiecutter::test-gha-cookiecutter ALIAS
            test-gha-cookiecutter)
# Install the library target and its public headers
install(
  TARGETS test-gha-cookiecutter
  EXPORT test-gha-cookiecutter-config
  FILE_SET HEADERS)

# Export the installed target into a simple <Project>-config file, so that
# find_package(test-gha-cookiecutter) works for consumers
install(
  EXPORT test-gha-cookiecutter-config
  NAMESPACE test-gha-cookiecutter::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/test-gha-cookiecutter)

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
