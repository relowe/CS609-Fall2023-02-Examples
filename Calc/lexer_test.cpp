#include <iostream>
#include "lexer.h"


int main()
{
  Lexer lex(std::cin);

  do {
    std::cout << lex.next() << std::endl;
  } while(lex.cur().tok != EOI);
}