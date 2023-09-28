// File: parser.h
// Purpose: Class definition for a recursive descent parser.
#include "lexer.h"

class Parser 
{
public:
  // construct a parser for a given lexer
  Parser(Lexer *_lex);

  // attempt to parse the program
  void parse();

private:
  Lexer *_lex;    // lexer for the stream we are parsing

  ////////////////////////////////////////
  // Lexer Convenience Interface
  ////////////////////////////////////////

  // return true if we have the given token in the buffer, false otherwise
  bool has(Token tok);

  // return true if we have the given token, report error otherwise
  // this will terminate the program on error
  bool must_be(Token tok);

  // return the current token and advance the lexer
  Lexer_Token consume(); 

  ////////////////////////////////////////
  // Recursive Descent Parser Rules
  ////////////////////////////////////////
  void parse_Program();
  void parse_Statement();
  void parse_Expression();
  void parse_Expression2();
  void parse_Term();
  void parse_Term2();
  void parse_Factor();
  void parse_Factor2();
  void parse_Base();
  void parse_Number();
};