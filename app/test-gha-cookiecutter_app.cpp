#include "test-gha-cookiecutter/test-gha-cookiecutter.hpp"
#include <iostream>

int
main()
{
  int result = testghacookiecutter::add_one(1);
  std::cout << "1 + 1 = " << result << std::endl;
}
