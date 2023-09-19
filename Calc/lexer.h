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
  std::string _cur_lexeme;
  int _line;
  int _col;
  std::istream &_is;

  // read the next character from the stream
  void read();
};

#endif