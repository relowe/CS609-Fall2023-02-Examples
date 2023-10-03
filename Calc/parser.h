// File: parser.h
// Purpose: Class definition for a recursive descent parser.
#include "lexer.h"
#include "parse_tree.h"

class Parser 
{
public:
  // construct a parser for a given lexer
  Parser(Lexer *_lex);

  // attempt to parse the program
  Parse_Tree* parse();

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
  Parse_Tree* parse_Program();
  Parse_Tree* parse_Statement();
  Parse_Tree* parse_Expression();
  Parse_Tree* parse_Expression2(Parse_Tree *left);
  Parse_Tree* parse_Term();
  Parse_Tree* parse_Term2(Parse_Tree *left);
  Parse_Tree* parse_Factor();
  Parse_Tree* parse_Factor2(Parse_Tree *left);
  Parse_Tree* parse_Base();
  Parse_Tree* parse_Number();
};