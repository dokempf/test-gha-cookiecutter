cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(citest VERSION 0.0.1 LANGUAGES CXX)

# Initialize some default paths
include(GNUInstallDirs)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Compilation options
option(BUILD_PYTHON "Enable building of Python bindings" ON)
option(BUILD_DOCS "Enable building of documentation" ON)
# Add an interface target for our header-only library
add_library(citest INTERFACE)
target_include_directories(citest INTERFACE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# compile the application
add_subdirectory(app)

# compile the tests
include(CTest)
if(BUILD_TESTING)
  find_package(Catch2 REQUIRED)
  include(Catch)
  add_subdirectory(tests)
endif()

if(BUILD_DOCS)
  # Add the documentation
  add_subdirectory(doc)
endif()
if(BUILD_PYTHON)
  # Add Python bindings
  find_package(pybind11)
  # Compile the Pybind11 module
  pybind11_add_module(_citest python/citest/_citest.cpp)
  target_link_libraries(_citest PUBLIC citest)

  # Install the Python module shared library
  install(TARGETS _citest DESTINATION .)
endif()

# Add an alias target for use if this project is included as a subproject in another project
add_library(citest::citest ALIAS citest)

# Install targets and configuration
install(
  TARGETS citest
  EXPORT citest-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
  EXPORT citest-config
  NAMESPACE citest::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/citest
)

install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
