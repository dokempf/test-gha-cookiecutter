add_executable(tests tests.cpp citest_t.cpp)
target_link_libraries(tests PUBLIC citest Catch2::Catch2)

# allow user to run tests with `make test` or `ctest`
catch_discover_tests(tests)
