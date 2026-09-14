find_package(Doxygen REQUIRED)
set(DOXYGEN_EXCLUDE_PATTERNS "${CMAKE_SOURCE_DIR}/ext/*")
set(DOXYGEN_SHORT_NAMES YES)
set(DOXYGEN_GENERATE_XML YES)

doxygen_add_docs(test-gha-cookiecutter-doxygen
  ${CMAKE_SOURCE_DIR}/include
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT Building doxygen documentation...
)

add_custom_target(test-gha-cookiecutter-sphinx-doc
  COMMAND
    sphinx-build -b html
    -Dbreathe_projects.test-gha-cookiecutter="${CMAKE_CURRENT_BINARY_DIR}/xml"
    -c ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/sphinx
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Generating documentation with Sphinx..."
)
add_dependencies(test-gha-cookiecutter-sphinx-doc test-gha-cookiecutter-doxygen)
