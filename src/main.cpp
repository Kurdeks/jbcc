#include "parser.hpp"
#include <cstdlib>
#include <iostream>

int main() {

  if (yyparse())
    std::cout << "SUCCESS\n";
  return EXIT_SUCCESS;
}