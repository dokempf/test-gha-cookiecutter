add_executable(tests tests.cpp test-gha-cookiecutter_t.cpp)
target_link_libraries(tests PUBLIC test-gha-cookiecutter Catch2::Catch2)

# allow user to run tests with `make test` or `ctest`
catch_discover_tests(tests)
