// File: lexer.cpp
// Purpose: Implementation of the lexer
#include "lexer.h"

////////////////////////////////////////
// Lexer_Token Implementation
////////////////////////////////////////
Lexer_Token::Lexer_Token(Token tok, const std::string &lexeme, int line,
                         int col) {
  this->tok = tok;
  this->lexeme = lexeme;
  this->line = line;
  this->col = col;
}

std::ostream &operator<<(std::ostream &os, const Lexer_Token &t) {
  std::string token_label[] = {"INVALID", "EOI", "NEWLINE", "PLUS", "MINUS", "TIMES", "DIVIDE", "MOD", "POW", "LPAREN", "RPAREN", "INTLIT", "REALLIT"};
  return os << token_label[t.tok] << ": \"" << t.lexeme << "\" Line: " << t.line << " Column: " << t.col;
}


////////////////////////////////////////
// Lexer Implementation 
////////////////////////////////////////

// constructor
Lexer::Lexer(std::istream &_is) : _is(_is)
{
  // initialize fields
  _line = 1;
  _col = 0;
  _cur.tok = INVALID;

  // advance to the first character
  read();
}

// get the next token in the stream
Lexer_Token Lexer::next()
{
  _cur_lexeme = "";
  
  // update the current token
  _cur_lexeme += _cur_char;
  _cur = Lexer_Token(INVALID, _cur_lexeme, _line, _col);

  // advance the lexer
  read();

  return _cur;
}

// get the current token
Lexer_Token Lexer::cur() {
  return _cur;
}


// read the next character from the stream
void Lexer::read() {
  // count lines
  if(_cur_char == '\n') {
    _line++;
    _col = 0;
  }

  // read the character, advance the column
  _cur_char = _is.get();
  _col++;
}