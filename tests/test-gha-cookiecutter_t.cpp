#include "test-gha-cookiecutter/test-gha-cookiecutter.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace testghacookiecutter;

TEST_CASE("add_one", "[adder]")
{
  REQUIRE(add_one(0) == 1);
  REQUIRE(add_one(123) == 124);
  REQUIRE(add_one(-1) == 0);
}
