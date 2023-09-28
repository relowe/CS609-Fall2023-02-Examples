// Test the parser
#include <iostream>
#include "parser.h"

int main()
{
  // make a lexer on the cin stream
  Lexer *lex = new Lexer(std::cin);

  // create the parser
  Parser parser(lex);

  // run the parser
  parser.parse();
}