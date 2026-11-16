# Declare an executable target
add_executable(test-gha-cookiecutter_app)

# Add source files to the executable target
target_sources(test-gha-cookiecutter_app
  PRIVATE
    test-gha-cookiecutter_app.cpp
)

# Link the executable against the library
target_link_libraries(test-gha-cookiecutter_app
  PRIVATE
    test-gha-cookiecutter
)
