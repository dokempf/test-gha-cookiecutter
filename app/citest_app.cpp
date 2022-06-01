#include "citest/citest.hpp"
#include <iostream>

int main(){
  int result = citest::add_one(1);
  std::cout << "1 + 1 = " << result << std::endl;
}