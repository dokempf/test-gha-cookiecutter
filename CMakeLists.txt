cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(test-github-actions-cookiecutter-cpp-project VERSION 0.0.1 LANGUAGES CXX)

# Initialize some default paths
include(GNUInstallDirs)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Compilation options
set(BUILD_PYTHON ON CACHE BOOL "Enable building of Python bindings")
set(BUILD_DOCS ON CACHE BOOL "Enable building of documentation")
# Add an interface target for our header-only library
add_library(test-github-actions-cookiecutter-cpp-project INTERFACE)
target_include_directories(test-github-actions-cookiecutter-cpp-project INTERFACE
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
  add_subdirectory(python)
endif()

# Add an alias target for use if this project is included as a subproject in another project
add_library(test-github-actions-cookiecutter-cpp-project::test-github-actions-cookiecutter-cpp-project ALIAS test-github-actions-cookiecutter-cpp-project)

# Install targets and configuration
install(
  TARGETS test-github-actions-cookiecutter-cpp-project
  EXPORT test-github-actions-cookiecutter-cpp-project-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
  EXPORT test-github-actions-cookiecutter-cpp-project-config
  NAMESPACE test-github-actions-cookiecutter-cpp-project::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/test-github-actions-cookiecutter-cpp-project
)

install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
