#include "test-github-actions-cookiecutter-cpp-project/test-github-actions-cookiecutter-cpp-project.hpp"
#include "catch2/catch.hpp"

using namespace testgithubactionscookiecuttercppproject;

TEST_CASE( "add_one", "[adder]" ){
  REQUIRE(add_one(0) == 1);
  REQUIRE(add_one(123) == 124);
  REQUIRE(add_one(-1) == 0);
}