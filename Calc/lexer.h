
// File: lexer.h
// Purpose: A lexer for the calc programming language.
#include <string>
#include <iostream>

#ifndef LEXER_H
#define LEXER_H

// Use an enumeration to implement our tokens
enum Token {
  INVALID=0,
  EOI,
  NEWLINE,
  PLUS,
  MINUS,
  TIMES,
  DIVIDE,
  MOD,
  POW,
  LPAREN,
  RPAREN,
  INTLIT,
  REALLIT
};

// The actual tokens emitted by our lexer
class Lexer_Token
{
public:
  Lexer_Token();
  Lexer_Token(Token tok, const std::string &lexeme, int line, int col);
  Token tok;             // numeric token
  std::string lexeme;    // actual text
  int line;              // line of the token
  int col;               // column token
};
std::ostream &operator<<(std::ostream &os, const Lexer_Token &t);


class Lexer
{
public:
  // constructor
  Lexer(std::istream &_is);

  // get the next token in the stream
  Lexer_Token next();

  // get the current token
  Lexer_Token cur();

private:
  char _cur_char;    // the current character we are matching
  Lexer_Token _cur; // the current token
  int _line;
  int _col;
  std::istream &_is;

  // read the next character from the stream
  void read();

  // consume the current character and add it to the lexeme
  void consume();

  // skip insiginficant characters
  void skip();

  // attempt to match single character tokens
  bool lex_single();

  // attempt to match a number
  bool lex_number();

  // attempt to match a keyword or identifier
  bool lex_kw_or_id();
};

#endif