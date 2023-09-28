// File: lexer.cpp
// Purpose: Implementation of the lexer
#include <map>
#include "lexer.h"

////////////////////////////////////////
// Lexer_Token Implementation
////////////////////////////////////////
Lexer_Token::Lexer_Token()
{
  this->tok = INVALID;
  this->line = 0;
  this->col = 0;
}


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
  // skip things we don't car about
  skip();

  // is this the end of the file?
  if(not _is) {
    _cur = Lexer_Token(EOI, "", _line, _col);
    return _cur;
  }
  
  // start the token
  _cur = Lexer_Token(INVALID, "", _line, _col);

  // attempt to match
  if(lex_single()) {
    // nothing to do
  } else if(lex_number()) {
    // nothing to do
  } else if(lex_kw_or_id()) {
    // nothing to do
  } else {
    // and invalid token
    consume();
    _cur.tok = INVALID;
  }


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
  if(_is) {
    //detect end of stream or an error
    _col++;
  }
}

// consume the current character and add it to the lexeme
void Lexer::consume()
{
  _cur.lexeme += _cur_char;
  read();
}

// skip insiginficant characters
void Lexer::skip()
{
  while(_is and (_cur_char == '\t' or _cur_char == ' ')) {
    read();
  }
}


// attempt to match single character tokens
bool Lexer::lex_single()
{
  std::map<char, Token> tokens;
  tokens['\n'] = NEWLINE;
  tokens['+'] = PLUS;
  tokens['-'] = MINUS;
  tokens['*'] = TIMES;
  tokens['/'] = DIVIDE;
  tokens['^'] = POW; 
  tokens['('] = LPAREN; 
  tokens[')'] = RPAREN;


  // if we have the current character, we matched the token
  auto itr = tokens.find(_cur_char);
  if(itr == tokens.end()) {
    //did not find it
    return false;
  }

  // we found a token! build it
  consume();
  _cur.tok = itr->second;

  return true;
}


// attempt to match a number
bool Lexer::lex_number()
{
  // if we have no digits, we return false
  if(!isdigit(_cur_char)) {
    return false;
  }

  // We have an INTLIT so far
  _cur.tok = INTLIT;

  // consume all the digits
  while(isdigit(_cur_char)) {
    consume();
  }

  // we have matched an int
  if(_cur_char!='.') {
    return true;
  }

  // transition to invalid and consume the dot
  _cur.tok = INVALID;
  consume();

  if(isdigit(_cur_char)) {
    _cur.tok = REALLIT;
  }

  // consume any remaining digits
  while(isdigit(_cur_char)) {
    consume();
  }

  return true;
}


// attempt to match a keyword or identifier
bool Lexer::lex_kw_or_id()
{
  std::map<std::string, Token> tokens;
  tokens["MOD"] = MOD;
  
  //must begin with a letter or underscore
  if(!isalpha(_cur_char) and _cur_char != '_') {
    return false;
  }

  // consume all of the alphanumeric, _ characters
  while(isalnum(_cur_char) or _cur_char == '_') {
    consume();
  }

  // see if our token matches
  auto itr = tokens.find(_cur.lexeme);
  if(itr!=tokens.end()) {
    _cur.tok = itr->second;
  } else {
    _cur.tok = INVALID; // TODO: Change this once we make variables
  }

  return true;
}