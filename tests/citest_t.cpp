#include "citest/citest.hpp"
#include "catch2/catch.hpp"

using namespace citest;

TEST_CASE( "add_one", "[adder]" ){
  REQUIRE(add_one(0) == 1);
  REQUIRE(add_one(123) == 124);
  REQUIRE(add_one(-1) == 0);
}