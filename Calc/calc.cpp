// File: calc.cpp
// Purpose: This is the interpreter for the calc program
#include <iostream>
#include <sstream>
#include <string>
#include "lexer.h"
#include "parser.h"
#include "parse_tree.h"


// REPL (Read Execute Print Loop) Routine
void calc_repl();


int main(int argc, char **argv) {
  // TODO: We will eventually add file processing.
  //       For now, we just call the repl loop

  calc_repl();
}

// REPL (Read Execute Print Loop) Routine
void calc_repl()
{
  Lexer *lexer;
  Parser *parser;
  EvalResult result;
  std::string line;
  std::istringstream is;

  while(std::cin) {
    // get a string, break if there isn't one
    std::cout << "> ";
    getline(std::cin, line);
    if(not std::cin) continue;

    // build the string stream
    is = std::istringstream(line+"\n");

    // build the lexer and parser
    lexer = new Lexer(is);
    parser = new Parser(lexer);

    // run the parser
    Parse_Tree *program = parser->parse();

    // evaluate the line
    result = program->eval();

    // print the result
    if(result.type() == INTEGER) {
      std::cout << result.as_integer() << std::endl;
    } else {
      std::cout << result.as_real() << std::endl;
    }

    // clean up
    delete lexer;
    delete parser;
    delete program;
  }
}