#include "test-github-actions-cookiecutter-cpp-project/test-github-actions-cookiecutter-cpp-project.hpp"
#include <iostream>

int main(){
  int result = testgithubactionscookiecuttercppproject::add_one(1);
  std::cout << "1 + 1 = " << result << std::endl;
}