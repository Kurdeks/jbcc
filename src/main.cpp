#include "parser.hpp"
#include <cstdlib>
#include <iostream>

int main() {

  if (yyparse())
    printf("Parsing Successful\n");
  return 0;
}