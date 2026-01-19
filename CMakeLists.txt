cmake_minimum_required(VERSION 3.23)

# Set a name and a version number for your project:
project(test-gha-cookiecutter
  VERSION 0.0.1
  LANGUAGES CXX
)

# Initialize some default paths
include(GNUInstallDirs)

# Enable PIC for Python bindings
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(PROJECT_IS_TOP_LEVEL)
  option(test-gha-cookiecutter_BUILD_PYTHON "Enable building of Python bindings" ON)
else()
  option(test-gha-cookiecutter_BUILD_PYTHON "Enable building of Python bindings" OFF)
endif()

if(PROJECT_IS_TOP_LEVEL)
  option(test-gha-cookiecutter_BUILD_DOCS "Enable building of documentation" ON)
else()
  option(test-gha-cookiecutter_BUILD_DOCS "Enable building of documentation" OFF)
endif()

# Add an interface target for the header-only library
add_library(test-gha-cookiecutter INTERFACE)

# Add the public headers that belong to this library
target_sources(test-gha-cookiecutter
  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/test-gha-cookiecutter/test-gha-cookiecutter.hpp
)

# Request a minimum C++ standard for this target
target_compile_features(test-gha-cookiecutter
  INTERFACE
    cxx_std_14
)

if(PROJECT_IS_TOP_LEVEL)
  # Compile the application executable
  add_subdirectory(app)
endif()

if(PROJECT_IS_TOP_LEVEL)
  # Compile the tests
  include(CTest)
  if(BUILD_TESTING)
    add_subdirectory(tests)
  endif()
endif()

# Add the documentation
if(PROJECT_IS_TOP_LEVEL AND test-gha-cookiecutter_BUILD_DOCS)
  add_subdirectory(doc)
endif()

# Add Python bindings
if(PROJECT_IS_TOP_LEVEL AND test-gha-cookiecutter_BUILD_PYTHON)
  set(PYBIND11_FINDPYTHON ON)
  find_package(pybind11 REQUIRED)
  # Compile the Pybind11 module
  pybind11_add_module(_testghacookiecutter python/testghacookiecutter/_test-gha-cookiecutter.cpp)
  target_link_libraries(_testghacookiecutter
    PUBLIC
      test-gha-cookiecutter
  )

  # Install the Python module shared library
  install(TARGETS _testghacookiecutter DESTINATION .)
endif()

# Add an alias target for use if this project is included as a subproject in another project
add_library(test-gha-cookiecutter::test-gha-cookiecutter ALIAS test-gha-cookiecutter)

# Install the target and headers
install(
  TARGETS test-gha-cookiecutter
  EXPORT test-gha-cookiecutterTargets
  FILE_SET HEADERS
)

# Install the exported targets (this creates test-gha-cookiecutterTargets.cmake)
install(
  EXPORT test-gha-cookiecutterTargets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/test-gha-cookiecutter
  NAMESPACE test-gha-cookiecutter::
)

# Include helpers for calling configure_package_config_file
include(CMakePackageConfigHelpers)

# Generate the test-gha-cookiecutterConfig.cmake file
configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/cmake/test-gha-cookiecutterConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/test-gha-cookiecutterConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/test-gha-cookiecutter
)

# Install the generated Config file
install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/test-gha-cookiecutterConfig.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/test-gha-cookiecutter
)

# Generate a version file
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/test-gha-cookiecutterConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

# Install the version file
install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/test-gha-cookiecutterConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/test-gha-cookiecutter
)

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
