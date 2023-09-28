
// File: parser.cpp
// Purpose: Implementation of the parser class.
#include "parser.h"
#include <iostream>

// construct a parser for a given lexer
Parser::Parser(Lexer *_lex) {
  // get the lexer
  this->_lex = _lex;

  // make sure the lexer has a token
  _lex->next();
}

// attempt to parse the program
void Parser::parse() { parse_Program(); }

////////////////////////////////////////
// Lexer Convenience Interface
////////////////////////////////////////

// return true if we have the given token in the buffer, false otherwise
bool Parser::has(Token tok) { return _lex->cur().tok == tok; }

// return true if we have the given token, report error otherwise
// this will terminate the program on error
bool Parser::must_be(Token tok) {
  // if we have this, everything is good
  if (has(tok)) {
    return true;
  }

  // if we make it here, that's an error
  std::cerr << "Parse Error: Unexpected Token " << _lex->cur() << std::endl;
  exit(-1);
}

// return the current token and advance the lexer
Lexer_Token Parser::consume() {
  Lexer_Token t = _lex->cur();
  _lex->next();

  return t;
}

////////////////////////////////////////
// Recursive Descent Parser Rules
////////////////////////////////////////

/*
< Program >    ::= < Statement > < Program' >

< Program' >   ::= < Statement > < Program' >
                   | ""
 */
void Parser::parse_Program() {
  // effectively, this reads statements until EOI
  while (not has(EOI)) {
    parse_Statement();
  }
}

/*
< Statement >  ::= < Expression > NEWLINE
 */

// If a expression is followed by newline, then consume it and parse the
// expression if not the system will report the error and exit.
void Parser::parse_Statement() {
  parse_Expression();
  if (must_be(NEWLINE)) {
    consume();
  }
}

/*
< Expression > ::= < Term > < Expression' >
 */
void Parser::parse_Expression() {
  parse_Term();
  parse_Expression2();
}

/*
< Expression' > ::= PLUS < Term > < Expression' >
                    | MINUS < Term > < Expression' >
                    | ""
 */
void Parser::parse_Expression2() {
  if (has(PLUS)) {
    // consume the plus
    consume();
    parse_Term();
    parse_Expression2();
  } else if (has(MINUS)) {
    // consume the minus
    consume();
    parse_Term();
    parse_Expression2();
  }

  // do nothingon ""
}

/*
< Term >       ::=  < Factor > < Term' >
 */
void Parser::parse_Term() {
  parse_Factor();
  parse_Term2();
}

/*
< Term' >      ::=  TIMES < Factor > < Term' >
                  | DIVIDE < Factor > < Term' >
                  | MOD < Factor > < Term' >
                  | ""
 */
void Parser::parse_Term2() {
  if (has(TIMES)) {
    consume();
    parse_Factor();
    parse_Term2();
  } else if (has(DIVIDE)) {
    consume();
    parse_Factor();
    parse_Term2();
  } else if (has(MOD)) {
    consume();
    parse_Factor();
    parse_Term2();
  }
}

/*
< Factor >       ::= < Base > < Factor' >
 */
void Parser::parse_Factor() {
  parse_Base();
  parse_Factor2();
}

/*
< Factor' >      ::= POW < Factor >
                     | ""
 */
void Parser::parse_Factor2() {
  if (has(POW)) {
    consume();
    parse_Factor();
  }
}

/*
< Base >         ::= LPAREN < Expression > RPAREN
                     | MINUS < Expression >
                     | < Number >
 */
void Parser::parse_Base() {
  if (has(LPAREN)) {
    consume();
    parse_Expression();
    must_be(RPAREN);
    consume();
  } else if (has(MINUS)) {
    consume();
    parse_Expression();

  } else {
    parse_Number();
  }
}

/*
< Number >       ::= INTLIT
                     | REALLIT
 */
void Parser::parse_Number() {
  if (has(INTLIT)) {
    consume();
  } else if (must_be(REALLIT)) {
    consume();
  }
}